#include <bits/stdc++.h>
using namespace std;
const int nh = 200013, m7 = 1000000007, m99 = 998244353;
const int ogo = m7, nhl = 18, mh = nh;
const double eps = 1e-9;
int n, m, c;
const int mk = 450;
int x[nh], y[nh], s[nh], prf[nh], mt[mk][mk];
void ad(int h, int na, int xad) {
  int bl = x[h] + y[h], l = (na + x[h]) % bl, r = (na - 1) % bl;
  if (l <= r)
    for (int i = l; i < r + 1; i++) mt[bl][i] += xad;
  else {
    for (int i = 0; i < r + 1; i++) mt[bl][i] += xad;
    for (int i = l; i < bl; i++) mt[bl][i] += xad;
  }
}
int mkm(int na) {
  int o = 0;
  for (int i = 2; i < mk; i++) o += mt[i][na % i];
  return o;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i < n + 1; i++) cin >> x[i] >> y[i];
  for (int i = 1; i < m + 1; i++) {
    int qt, k;
    cin >> qt >> k;
    if (qt == 1) {
      if (mk <= x[k] + y[k]) {
        for (int j = i + x[k]; j <= m; j += x[k] + y[k]) {
          prf[j]++;
          if (j + y[k] <= m) prf[j + y[k]]--;
        }
      } else
        ad(k, i, 1);
      s[k] = i;
    } else {
      if (mk <= x[k] + y[k]) {
        for (int j = s[k] + x[k]; j <= m; j += x[k] + y[k]) {
          prf[j]--;
          if (j + y[k] <= m) prf[j + y[k]]++;
          if (j < i && j + y[k] >= i) c--;
        }
      } else
        ad(k, s[k], -1);
    }
    c += prf[i];
    cout << c + mkm(i) << "\n";
  }
  return 0;
}
