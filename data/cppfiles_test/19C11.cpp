#include <bits/stdc++.h>
using namespace std;
const int nh = 2000013, m7 = 2000000007, m99 = 998244353;
const int ogo = m7, nhl = 18, mh = nh;
const double eps = 1e-9;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int o0o;
  cin >> o0o;
  while (o0o--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> d(2001), d0;
    for (int i = 0; i < a[0]; i++) d[i] = 2000;
    for (int i = 1; i < n; i++) {
      d0.assign(2001, 2000);
      for (int h = 0; h < 2001; h++)
        if (d[h] < 2000) {
          if (a[i] <= h) d0[h - a[i]] = min(d0[h - a[i]], a[i] + d[h]);
          if (h + a[i] < 2001)
            d0[h + a[i]] = min(d0[h + a[i]], max(d[h] - a[i], 0));
        }
      d = d0;
    }
    int c = 2001;
    for (int i = 0; i < 2001; i++) c = min(c, d[i] + i);
    cout << c << "\n";
  }
  return 0;
}
