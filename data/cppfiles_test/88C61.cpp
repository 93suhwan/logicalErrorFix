#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e14 + 7;
int N, M;
int a[305 * 305], b[305][305];
vector<int> pos[100005];
vector<int> ppos[100005];
void solve() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= (int)(N * M); ++i) scanf("%d", &a[i]);
  vector<int> v;
  for (int i = 1; i <= (int)(N * M); ++i) v.push_back(a[i]);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 1; i <= (int)(N * M); ++i)
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
  for (int i = 1; i <= (int)(N * M); ++i) pos[i].clear(), ppos[i].clear();
  for (int i = 1; i <= (int)(N * M); ++i) pos[a[i]].push_back(i);
  sort(a + 1, a + N * M + 1);
  for (int i = 1; i <= (int)(N * M); ++i) ppos[a[i]].push_back(i);
  for (int i = 1; i <= (int)(N * M); ++i) {
    sort(ppos[i].begin(), ppos[i].end(), [&](int x, int y) {
      int rx = (x - 1) / M;
      int ry = (y - 1) / M;
      if (rx != ry) return rx < ry;
      return x > y;
    });
    for (int j = 0; j < (int)(ppos[i].size()); ++j) {
      int r = (ppos[i][j] - 1) / M + 1;
      int c = (ppos[i][j] - 1) % M + 1;
      b[r][c] = pos[i][j];
    }
  }
  long long ret = 0;
  for (int i = 1; i <= (int)(N); ++i)
    for (int j = 1; j <= (int)(M); ++j)
      for (int k = 1; k < j; ++k) {
        if (b[i][j] > b[i][k]) ret++;
      }
  printf("%lld\n", ret);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
