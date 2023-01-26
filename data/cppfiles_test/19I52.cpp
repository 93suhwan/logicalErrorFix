#include <bits/stdc++.h>
using namespace std;
const int nh = 1000013, m7 = 1000000007, m99 = 998244353;
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
    vector<int> dl(2001), dl0, dr(2001), dr0, q, q0;
    dl[1000 + a[0]] = 1000, dr[1000 + a[0]] = 1000 + a[0];
    for (int i = 1; i < n; i++) {
      dl0.assign(2001, 0), dr0.assign(2001, 0);
      for (int h = 0; h < 2001; h++)
        if (dr[h] - dl[h]) {
          int p = h - a[i];
          if (p >= 0 && (dr0[p] - dl0[p] == 0 ||
                         dr0[p] - dl0[p] > dr[h] - min(dl[h], p))) {
            dl0[p] = min(dl[h], p), dr0[p] = dr[h];
          }
          p = h + a[i];
          if (p <= 2000 && (dr0[p] - dl0[p] == 0 ||
                            dr0[p] - dl0[p] > max(dr[h], p) - dl[h])) {
            dl0[p] = dl[h], dr0[p] = max(dr[h], p);
          }
        }
      dl = dl0, dr = dr0;
    }
    int c = 2001;
    for (int i = 0; i < 2001; i++)
      if (dr[i] - dl[i]) c = min(c, dr[i] - dl[i]);
    cout << c << "\n";
  }
  return 0;
}
