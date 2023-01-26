#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <class T>
inline void amin(T &x, const T &y) {
  if (y < x) x = y;
}
template <class T>
inline void amax(T &x, const T &y) {
  if (x < y) x = y;
}
int N, M;
int A[1011];
int B[1011];
int X[2011];
int Y[2011];
vector<int> G[1011];
bool is_root[1011];
vector<int> que;
int parent[1011];
int parent_edge[1011];
bool vis[1011];
long long S[1011];
int anti(int v, int j) {
  int x = X[j];
  int y = Y[j];
  if (is_root[x]) x = 0;
  if (is_root[y]) y = 0;
  return v ^ x ^ y;
}
bool ok(long long mid) {
  memset(is_root, 0, sizeof is_root);
  is_root[0] = true;
  int rest = N;
  while (1) {
    memset(S, 0, sizeof S);
    S[0] = mid;
    for (int i = 0, i_len = (N); i < i_len; ++i) G[i].clear();
    for (int j = 0, j_len = (M); j < j_len; ++j) {
      int x = X[j];
      int y = Y[j];
      if (is_root[x]) x = 0;
      if (is_root[y]) y = 0;
      if (x == 0 && y == 0) continue;
      G[x].push_back(j);
      G[y].push_back(j);
    }
    que.clear();
    que.push_back(0);
    memset(vis, 0, sizeof vis);
    vis[0] = true;
    int find_x = -1, find_y = -1;
    for (int i_ = 0; i_ < (int)que.size(); i_++) {
      int v = que[i_];
      for (__typeof((G[v]).begin()) e = (G[v]).begin(), e_end = (G[v]).end();
           e != e_end; ++e) {
        int w = anti(v, *e);
        if (vis[w] && *e == parent_edge[v]) continue;
        if (vis[w]) {
          find_x = v;
          find_y = w;
          goto OUT;
        } else if (A[w] < S[v]) {
          vis[w] = true;
          parent[w] = v;
          parent_edge[w] = *e;
          S[w] = S[v] + B[w];
          que.push_back(w);
        }
      }
    }
  OUT:
    if (find_x == -1) return false;
    while (find_x != 0) {
      mid += B[find_x];
      is_root[find_x] = true;
      rest--;
      find_x = parent[find_x];
    }
    while (find_y != 0) {
      mid += B[find_y];
      is_root[find_y] = true;
      rest--;
      find_y = parent[find_y];
    }
    if (rest == 1) return true;
  }
}
void MAIN() {
  scanf("%d%d", &N, &M);
  for (int i = 0, i_len = (N - 1); i < i_len; ++i) scanf("%d", A + i + 1);
  for (int i = 0, i_len = (N - 1); i < i_len; ++i) scanf("%d", B + i + 1);
  for (int j = 0, j_len = (M); j < j_len; ++j) {
    scanf("%d%d", X + j, Y + j);
    X[j]--;
    Y[j]--;
  }
  long long lo = -1, hi = 1000000000;
  while (hi - lo > 1) {
    long long mid = (hi + lo) / 2;
    (ok(mid) ? hi : lo) = mid;
  }
  printf("%lld\n", hi);
}
int main() {
  int TC = 1;
  scanf("%d", &TC);
  for (int tc = 0, tc_len = (TC); tc < tc_len; ++tc) MAIN();
  return 0;
}
