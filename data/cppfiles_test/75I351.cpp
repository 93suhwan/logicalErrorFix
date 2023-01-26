#include <bits/stdc++.h>
using namespace std;
const int siz = 1e5;
int t, n;
vector<int> cvs[siz + 5];
vector<pair<int, int>> mnps;
void clear() {
  for (int i = 1; i <= n; ++i) {
    cvs[i].clear();
  }
  mnps.clear();
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      int sz;
      scanf("%d", &sz);
      while (sz--) {
        int v;
        scanf("%d", &v);
        cvs[i].push_back(v);
      }
    }
    for (int i = 1; i <= n; ++i) {
      int mnp = cvs[i][0] + 1;
      int curp = mnp + 1;
      int sz = cvs[i].size();
      for (int j = 1; j < sz; ++j) {
        if (curp <= cvs[i][j]) {
          mnp += cvs[i][j] + 1 - curp;
          curp = cvs[i][j] + 1;
        }
        ++curp;
      }
      mnps.push_back({mnp, i});
    }
    sort(mnps.begin(), mnps.end());
    int ans = mnps[0].first;
    int curp = ans + cvs[mnps[0].second].size();
    int sz = mnps.size();
    for (int i = 1; i < sz; ++i) {
      if (curp < mnps[i].first) {
        ans += mnps[i].first - curp;
        curp = mnps[i].first;
      }
      ++curp += cvs[mnps[i].second].size();
    }
    printf("%d\n", ans);
    clear();
  }
  return 0;
}
