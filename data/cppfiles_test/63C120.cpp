#include <bits/stdc++.h>
using namespace std;
int par1[100008];
int par2[100008];
vector<pair<int, int>> result;
int find1(int r) {
  if (par1[r] == r)
    return r;
  else
    return par1[r] = find1(par1[r]);
}
int find2(int r) {
  if (par2[r] == r)
    return r;
  else
    return par2[r] = find2(par2[r]);
}
int main() {
  int i, j, t, n, m1, m2, p, q, res = 0, uu, vv, uu2, vv2;
  cin >> n >> m1 >> m2;
  for (i = 1; i <= n; i++) {
    par1[i] = i;
    par2[i] = i;
  }
  for (i = 0; i < m1; i++) {
    cin >> p >> q;
    uu = find1(p);
    vv = find1(q);
    par1[uu] = vv;
  }
  for (i = 0; i < m2; i++) {
    cin >> p >> q;
    uu2 = find2(p);
    vv2 = find2(q);
    par2[uu2] = vv2;
  }
  for (i = 1; i <= n; i++) {
    for (j = i + 1; j <= n; j++) {
      uu = find1(i);
      vv = find1(j);
      uu2 = find2(i);
      vv2 = find2(j);
      if ((uu != vv) && (uu2 != vv2)) {
        res++;
        par1[uu] = vv;
        par2[uu2] = vv2;
        result.push_back({i, j});
      }
    }
  }
  cout << res << endl;
  for (i = 0; i < result.size(); i++) {
    cout << result[i].first << " " << result[i].second << endl;
  }
  return 0;
}
