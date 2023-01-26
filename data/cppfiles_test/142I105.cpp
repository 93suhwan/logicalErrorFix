#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> p;
bool is(int val) {
  int c = 0;
  vector<bool> pres(n, 0);
  bool flag = 0;
  for (int i = 0; i < m; i++) {
    c = 0;
    for (int j = 0; j < n; j++) {
      if (p[i][j] >= val) {
        pres[j] = true;
        c++;
      }
    }
    if (c > 1) flag = 1;
  }
  if (flag) return true;
  if (!flag && n > 1) return false;
  for (bool i : pres)
    if (!i) return false;
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> m >> n;
    p.assign(m, vector<int>(n));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) cin >> p[i][j];
    int l = 1, r = 2;
    while (is(r)) r *= 2;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (is(mid))
        l = mid;
      else
        r = mid;
    }
    cout << l << '\n';
  }
  return 0;
}
