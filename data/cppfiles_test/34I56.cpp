#include <bits/stdc++.h>
using namespace std;
const int N = 1000005, M = 1 << 13;
int n, a[N];
vector<int> g[N];
int r[M];
bool ans[N];
inline void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < M; ++i) {
    ans[i] = 0, g[i].push_back(0), r[i] = M;
  }
  for (int i = 1; i <= n; ++i) {
    int X = a[i];
    for (auto j : g[X]) {
      int nw = X ^ j;
      ans[nw] = 1;
      while (r[nw] > X) {
        --r[nw];
        g[r[nw]].push_back(nw);
      }
    }
    g[X].clear();
  }
  int tot = 0;
  for (int i = 0; i < M; ++i) {
    tot += ans[i];
  }
  printf("%d\n", tot);
  for (int i = 0; i < M; ++i) {
    if (ans[i]) {
      printf("%d ", i);
    }
  }
}
int main() {
  init();
  return 0;
}
