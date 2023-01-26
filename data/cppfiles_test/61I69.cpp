#include <bits/stdc++.h>
using namespace std;
long long modpow(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      ans *= a;
      ans %= 1000000007;
    }
    a *= a;
    a %= 1000000007;
    b /= 2;
  }
  return ans;
}
long long modinv(long long a) { return modpow(a, 1000000007 - 2); }
vector<long long> mf = {1};
vector<long long> mfi = {1};
long long modfact(int n) {
  if (mf.size() > n) {
    return mf[n];
  } else {
    for (int i = mf.size(); i <= n; i++) {
      long long next = mf.back() * i % 1000000007;
      mf.push_back(next);
      mfi.push_back(modinv(next));
    }
    return mf[n];
  }
}
long long modfactinv(int n) {
  if (mfi.size() > n) {
    return mfi[n];
  } else {
    return modinv(modfact(n));
  }
}
long long nCr(int n, int k) {
  if (n < 0 || k < 0 || k > n) {
    return 0;
  } else {
    return modfact(n) * modfactinv(k) % 1000000007 * modfactinv(n - k) %
           1000000007;
  }
}
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long nem = count(s.begin(), s.end(), '?');
  if (nem == n) {
    for (long long i = 0; i < n; i++) {
      if (i % 2 == 0) {
        s[i] = 'B';
      } else {
        s[i] = 'R';
      }
    }
    cout << s << "\n";
    return;
  }
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'B' && i != 0 && i != n - 1) {
      if (s[i - 1] == '?') {
        s[i - 1] = 'R';
      }
      if (s[i + 1] == '?') {
        s[i + 1] = 'R';
      }
    } else if (s[i] == 'R' && i != 0 && i != n - 1) {
      if (s[i - 1] == '?') {
        s[i - 1] = 'B';
      }
      if (s[i + 1] == '?') {
        s[i + 1] = 'B';
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'B' && i != 0 && i != n - 1) {
      if (s[i - 1] == '?') {
        s[i - 1] = 'R';
      }
      if (s[i + 1] == '?') {
        s[i + 1] = 'R';
      }
    } else if (s[i] == 'R' && i != 0 && i != n - 1) {
      if (s[i - 1] == '?') {
        s[i - 1] = 'B';
      }
      if (s[i + 1] == '?') {
        s[i + 1] = 'B';
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    if (i == 0 && s[i] == '?') {
      if (s[i + 1] == 'B') {
        s[i] = 'R';
      } else {
        s[i] = 'B';
      }
    }
    if (i == n - 1 && s[i] == '?') {
      if (s[i - 1] == 'B') {
        s[i] = 'R';
      } else {
        s[i] = 'B';
      }
    }
  }
  cout << s << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
