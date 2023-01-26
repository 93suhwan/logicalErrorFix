#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, n, p, m, d, l, r, k;
  string s;
  cin >> t;
  while (t--) {
    d = 1;
    ;
    cin >> n >> m >> s;
    vector<int> f(n + 1);
    for (int i = 0; i < n; i++) {
      d ^= 1;
      if (s[i] == '+') {
        p = 1;
      } else {
        p = -1;
      }
      if (d == 0) {
        f[i + 1] = f[i] + p;
      } else {
        f[i + 1] = f[i] - p;
      }
    }
    while (m--) {
      cin >> l >> r;
      if (f[l - 1] == f[r]) {
        cout << 0 << endl;
      } else {
        if ((l - r) % 2 == 0) {
          cout << 1 << endl;
        } else {
          cout << 2 << endl;
        }
      }
    }
  }
  return 0;
}
