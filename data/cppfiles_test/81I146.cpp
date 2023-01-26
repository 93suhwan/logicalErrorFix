#include <bits/stdc++.h>
using namespace std;
long long int power(long long int b, long long int e) {
  if (e == 0) return 1;
  if (e % 2)
    return ((b * power((b) * (b), (e - 1) / 2)));
  else
    return power((b) * (b), e / 2);
}
long long int modpower(long long int b, long long int e, long long int q) {
  long long int MOD = q;
  if (e == 0) return 1;
  if (e % 2)
    return ((b % MOD) * modpower((b % MOD) * (b % MOD), (e - 1) / 2, q)) % MOD;
  else
    return modpower((b % MOD) * (b % MOD), e / 2, q) % MOD;
}
void dpv(vector<long long int> v) {
  for (long long int i = 0; i < (v.empty() ? 0 : v.size()); i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}
long long int ceil1(long long int x, long long int y) {
  long long int r = x / y;
  if (x % y == 0) {
    return r;
  } else {
    return r + 1;
  }
}
void fuck() {
  long long int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  long long int p[n];
  long long int pref = 0;
  for (long long int i = 0; i < n; i++) {
    if (i) {
      long long int c;
      if (s[i] == '+') {
        c = 1;
      } else {
        c = -1;
      }
      pref = (pref + power(-1, i % 2) * c);
    } else {
      long long int c;
      if (s[i] == '+') {
        c = 1;
      } else {
        c = -1;
      }
      pref = c;
    }
    p[i] = pref;
  }
  for (long long int i = 0; i < k; i++) {
    long long int l, r;
    cin >> l >> r;
    l--;
    r--;
    long long int val;
    if (l) {
      val = p[r] - p[l - 1];
    } else {
      val = p[r];
    }
    if (val == 0) {
      cout << 0 << "\n";
    } else {
      val = abs(val);
      long long int z = val / 3;
      cout << z + val % 3 << "\n";
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t = 1;
  cin >> t;
  long long int z = t;
  while (t--) {
    fuck();
  }
  return 0;
}
