#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long q;
  cin >> q;
  while (q--) {
    long long n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    long long ar[n];
    for (long long i = 0; i < n; ++i) {
      ar[i] = 2 * (s[i] == '+') - 1;
    }
    long long ps[n + 1][2];
    ps[0][0] = ps[0][1] = 0;
    for (long long i = 0; i < n; ++i) {
      ps[i + 1][0] = ps[i][0] + (2 * (i % 2 == 0) - 1) * ar[i];
      ps[i + 1][1] = ps[i][1] + (2 * (i % 2 == 1) - 1) * ar[i];
    }
    while (x--) {
      long long l, r;
      cin >> l >> r;
      l--;
      r--;
      long long d = (r - l + 1);
      long long s = ps[r + 1][l % 2] - ps[l][l % 2];
      if (s == 0) {
        cout << "0\n";
      } else if (d % 2 == 1) {
        cout << "1\n";
      } else {
        cout << "2\n";
      }
    }
  }
}
