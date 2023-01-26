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
const int maxN = 1 << 19, maxTS = maxN * 2, INF = maxN;
template <typename Tp>
struct Tree_t {
  int offset, qbegin, qend;
  Tp T[maxTS], res, x;
  void qpriv(int v, int left, int right) {
    if (left >= qend or right <= qbegin) return;
    if (left >= qbegin and right <= qend) {
      remin(res, T[v]);
      return;
    }
    qpriv(v * 2, left, (left + right) / 2);
    qpriv(v * 2 + 1, (left + right) / 2, right);
  }
  void updt(int v, Tp val) {
    for (v += offset; v != 0; v /= 2) remin(T[v], val);
  }
  void init(int n) {
    for (offset = 1; offset < n; offset *= 2)
      ;
    for (int i = (0); i < (offset * 2); i++) T[i] = make_pair(INF, INF);
  }
  Tp query(int a, int b) {
    qbegin = a + offset;
    qend = b + offset + 1;
    res = make_pair(INF, INF);
    qpriv(1, offset, offset * 2);
    return res;
  }
};
Tree_t<pair<int, int> > tree;
int dp[maxN], A[maxN], B[maxN], state[maxN], step[maxN];
vector<int> P[maxN];
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = (1); i < (n + 1); i++) scanf("%d", A + i);
  for (int i = (1); i < (n + 1); i++)
    scanf("%d", B + i), P[i + B[i]].push_back(i);
  tree.init(n + 1);
  tree.updt(0, {0, 0});
  for (int i = (1); i < (n + 1); i++) {
    auto x = tree.query(i - A[i], i);
    dp[i] = min(INF, x.first + 1);
    step[i] = x.second;
    for (int j : P[i]) tree.updt(j, {dp[i], j});
  }
  if (dp[n] == INF) {
    printf("-1\n");
    return;
  }
  printf("%d\n", dp[n]);
  for (int x = n; x != 0; x = step[x], x += B[x]) printf("%d ", step[x]);
  printf("\n");
}
int main() {
  int t = 1;
  for (int tid = (1); tid < (t + 1); tid++) {
    solve();
  }
  return 0;
}
