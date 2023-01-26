#include <bits/stdc++.h>
using namespace std;
vector<int> vv[200004];
vector<int> temp;
int res[200004];
int main() {
  int i, j, t, n, k, cnt, p, dd;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    int a[n + 1];
    for (i = 1; i <= n; i++) {
      res[i] = 0;
      cin >> a[i];
      vv[a[i]].push_back(i);
    }
    for (i = 1; i <= n; i++) {
      if (vv[i].size() >= k) {
        for (j = 0; j < k; j++) {
          res[vv[i][j]] = (j + 1);
        }
      } else {
        if (vv[i].size() >= 1)
          for (j = 0; j < vv[i].size(); j++) temp.push_back(vv[i][j]);
      }
    }
    cnt = (temp.size()) / k;
    p = 1;
    dd = 0;
    for (i = 0; i < temp.size(); i++) {
      if (dd == cnt) break;
      res[temp[i]] = p;
      if (p == k) dd++;
      p++;
      if (p == (k + 1)) p = 1;
    }
    for (i = 1; i <= n; i++) cout << res[i] << " ";
    cout << endl;
    temp.clear();
    for (i = 0; i <= n; i++) vv[i].clear();
  }
  return 0;
}
