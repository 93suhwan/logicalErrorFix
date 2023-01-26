#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <typename T1, typename T2>
inline void remin(T1& a, T2 b) {
  a = min(a, (T1)b);
}
template <typename T1, typename T2>
inline void remax(T1& a, T2 b) {
  a = max(a, (T1)b);
}
const int maxN = 1 << 19, INF = maxN;
int dp[maxN], A[maxN], B[maxN], state[maxN], step[maxN];
void go(int v) {
  if (v == 0) return;
  state[v] = 1;
  dp[v] = INF;
  for (int u = (v - A[v]); u < (v); u++) {
    int w = u + B[u];
    if (state[w] == 0) go(w);
    if (state[w] == 2)
      if (dp[v] > dp[w] + 1) dp[v] = dp[w] + 1, step[v] = u;
  }
  state[v] = 2;
}
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = (1); i < (n + 1); i++) scanf("%d", A + i);
  for (int i = (1); i < (n + 1); i++) scanf("%d", B + i);
  state[0] = 2;
  go(n);
  if (dp[n] == INF) {
    printf("-1\n");
    return;
  }
  printf("%d\n", dp[n]);
  for (int x = n; x != 0; x = step[x]) printf("%d ", step[x]);
  printf("\n");
}
int main() {
  int t = 1;
  for (int tid = (1); tid < (t + 1); tid++) {
    solve();
  }
  return 0;
}
