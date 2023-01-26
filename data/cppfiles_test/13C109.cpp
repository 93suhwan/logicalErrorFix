#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 16000001;
const long long inf = 1e18;
using ll = long long;
void fast_stream() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  string h = "";
  for (long long i = 0; i < m; i++) {
    h += 'a';
  }
  vector<string> sp(n);
  for (long long i = 0; i < n; i++) {
    sp[i] = h;
  }
  for (long long i = 0; i < m; i++) {
    if (i % 2 == 0) {
      for (long long j = 0; j < n; j++) {
        if (j % 4 <= 1) {
          sp[j][i] = 'y';
        } else {
          sp[j][i] = 'z';
        }
      }
    } else {
      for (long long j = 0; j < n; j++) {
        if (j % 4 <= 1) {
          sp[j][i] = 'w';
        } else {
          sp[j][i] = 'x';
        }
      }
    }
  }
  if (n % 2 == 0) {
    ll m1 = m / 2;
    m1 *= 2;
    ll mini = (m1 * n) / 2;
    if (k <= mini && k % 2 == 0) {
      cout << "YES" << '\n';
      for (long long i = 0; i < m1 / 2; i++) {
        if (i % 2 == 0) {
          ll num = n - 1;
          while (num >= 1 && k > 0) {
            sp[num][i * 2] = 'a';
            sp[num][i * 2 + 1] = 'a';
            sp[num - 1][i * 2] = 'b';
            sp[num - 1][i * 2 + 1] = 'b';
            num -= 2;
            k -= 2;
          }
        } else {
          ll num = n - 1;
          while (num >= 1 && k > 0) {
            sp[num][i * 2] = 'c';
            sp[num][i * 2 + 1] = 'c';
            sp[num - 1][i * 2] = 'd';
            sp[num - 1][i * 2 + 1] = 'd';
            num -= 2;
            k -= 2;
          }
        }
      }
      for (auto i : sp) {
        cout << i << '\n';
      }
    } else {
      cout << "NO" << '\n';
    }
  } else {
    ll sum = m / 2;
    if ((k - sum) % 2 == 0 && k >= sum) {
      cout << "YES" << '\n';
      for (long long i = 0; i < m / 2; i++) {
        if (i % 2 == 0) {
          sp[n - 1][i * 2] = 'e';
          sp[n - 1][i * 2 + 1] = 'e';
        } else {
          sp[n - 1][i * 2] = 'f';
          sp[n - 1][i * 2 + 1] = 'f';
        }
      }
      k = k - (m / 2);
      for (long long i = 0; i < m / 2; i++) {
        if (i % 2 == 0) {
          ll num = n - 2;
          while (num >= 1 && k > 0) {
            sp[num][i * 2] = 'a';
            sp[num][i * 2 + 1] = 'a';
            sp[num - 1][i * 2] = 'b';
            sp[num - 1][i * 2 + 1] = 'b';
            num -= 2;
            k -= 2;
          }
        } else {
          ll num = n - 2;
          while (num >= 1 && k > 0) {
            sp[num][i * 2] = 'c';
            sp[num][i * 2 + 1] = 'c';
            sp[num - 1][i * 2] = 'd';
            sp[num - 1][i * 2 + 1] = 'd';
            num -= 2;
            k -= 2;
          }
        }
      }
      for (auto i : sp) {
        cout << i << '\n';
      }
    } else {
      cout << "NO" << '\n';
    }
  }
}
signed main() {
  fast_stream();
  ll t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
