#include <bits/stdc++.h>
using namespace std;
long long mod_factorial[100005];
long long mod_inv_factorial[100005];
long long binpow(long long a, long long b) {
  long long res = 1LL;
  while (b) {
    if (b & 1) {
      res = (res * a);
    }
    a = (a * a);
    b >>= 1;
  }
  return res;
}
long long binpowmod(long long a, long long b, long long p) {
  long long res = 1LL;
  while (b) {
    if (b & 1) {
      res = (res * 1LL * a) % 1000000007;
    }
    a = (a * 1LL * a) % 1000000007;
    b >>= 1;
  }
  return res;
}
long long mod_inverse(long long a) {
  return binpowmod(a, 1000000007 - 2, 1000000007);
}
void precomputefact() {
  mod_factorial[0] = 1;
  for (int i = 1; i <= 1e5; i++) {
    mod_factorial[i] = (i * 1LL * mod_factorial[i - 1]) % 1000000007;
  }
  mod_inv_factorial[0] = 1;
  for (int i = 1; i <= 1e5; i++) {
    mod_inv_factorial[i] =
        ((mod_inv_factorial[i - 1]) * 1LL * mod_inverse(i)) % 1000000007;
  }
}
long long modbinomial(long long n, long long k, long long p) {
  long long ans = mod_factorial[n] * mod_inv_factorial[n - k] % 1000000007 *
                  mod_inv_factorial[k] % 1000000007;
  return ans;
}
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> temp;
  function<bool(pair<int, int>, pair<int, int>)> comp = [](pair<int, int> a,
                                                           pair<int, int> b) {
    if (a.first < b.first) {
      return true;
    } else if (a.first == b.first) {
      if (a.second > b.second) {
        return true;
      }
    }
    return false;
  };
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    temp.push_back(make_pair(l, r));
  }
  sort(temp.begin(), temp.end(), comp);
  for (int i = 0; i < temp.size(); i++) {
    int f = temp[i].first;
    int s = temp[i].second;
    if (f == s) {
      cout << f << " " << s << " " << f << "\n";
    } else {
      if (f == temp[i + 1].first) {
        cout << f << " " << s << " " << temp[i + 1].second + 1 << "\n";
      } else if (s == temp[i + 1].second) {
        cout << f << " " << s << " " << temp[i + 1].first - 1 << "\n";
      }
    }
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long testcase;
  cin >> testcase;
  while (testcase--) {
    solve();
  }
  return 0;
}
