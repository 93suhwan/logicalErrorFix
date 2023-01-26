#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int T;
int n, m;
vector<int> vec[1000010];
vector<int> mxl[1000010], mxr[1000010], mil[1000010], mir[1000010];
bool tag[1000010];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
      mxl[i].clear();
      mxr[i].clear();
      mil[i].clear();
      mir[i].clear();
      vec[i].clear();
      for (int j = 0; j < m; ++j) {
        int tmp;
        scanf("%d", &tmp);
        mxl[i].push_back(-0x3f3f3f3f);
        mxr[i].push_back(-0x3f3f3f3f);
        mil[i].push_back(0x3f3f3f3f);
        mir[i].push_back(0x3f3f3f3f);
        vec[i].push_back(tmp);
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (j != 0) {
          mxl[i][j] = max(mxl[i][j - 1], vec[i][j]);
          mil[i][j] = min(mil[i][j - 1], vec[i][j]);
        } else {
          mxl[i][j] = vec[i][j];
          mil[i][j] = vec[i][j];
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = m - 1; j >= 0; --j) {
        if (j != m - 1) {
          mxr[i][j] = max(mxr[i][j + 1], vec[i][j]);
          mir[i][j] = min(mir[i][j + 1], vec[i][j]);
        } else {
          mxr[i][j] = vec[i][j];
          mir[i][j] = vec[i][j];
        }
      }
    }
    bool flag = 0;
    for (int j = 0; j < m - 1 && !flag; ++j) {
      vector<pair<int, int>> pp;
      for (int i = 0; i < n; ++i) {
        pp.push_back({mil[i][j], i});
        tag[i] = 0;
      }
      sort(pp.begin(), pp.end());
      int maxxl = mxl[pp[0].second][j];
      int minnr = mir[pp[0].second][j + 1];
      multiset<int> se;
      for (int i = 1; i < n; ++i) {
        se.insert(-mxr[pp[i].second][j + 1]);
      }
      tag[pp[0].second] = 1;
      for (int i = 1; i < n; ++i) {
        auto it = se.begin();
        if (pp[i].first > maxxl && minnr > -(*it)) {
          flag = 1;
          printf("YES\n");
          for (int k = 0; k < n; ++k) {
            if (tag[k])
              printf("B");
            else
              printf("R");
          }
          printf(" %d\n", j + 1);
          break;
        }
        maxxl = max(maxxl, mxl[pp[i].second][j]);
        se.erase(it);
        minnr = min(minnr, mir[pp[i].second][j + 1]);
        tag[pp[i].second] = 1;
      }
    }
    if (!flag) {
      printf("NO\n");
    }
  }
  return 0;
}
