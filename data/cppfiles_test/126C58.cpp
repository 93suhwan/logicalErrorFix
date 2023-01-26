#include <bits/stdc++.h>
using namespace std;
namespace DinicFlows {
const int Inf = 0x3f3f3f3f;
const int MN = 1015, MM = 2005;
int N, S, T;
int h[MN], iter[MN], nxt[MM * 2], to[MM * 2], w[MM * 2], tot;
inline void SetST(int _S, int _T) { S = _S, T = _T; }
inline void Init(int _N) {
  N = _N, tot = 1;
  for (int i = 1; i <= N; ++i) h[i] = 0;
  SetST(_N - 1, _N);
}
inline void ins(int u, int v, int x) {
  if (tot + 1 >= MM * 2) {
    puts("Error : too many edges.");
    return;
  }
  nxt[++tot] = h[u], to[tot] = v, w[tot] = x, h[u] = tot;
}
inline void insw(int u, int v, int w1 = Inf, int w2 = 0) {
  if (!u) u = S;
  if (!v) v = T;
  ins(u, v, w1), ins(v, u, w2);
}
int lv[MN], que[MN], l, r;
inline bool Lvl() {
  for (int i = 1; i <= N; ++i) lv[i] = 0;
  lv[S] = 1;
  que[l = r = 1] = S;
  while (l <= r) {
    int u = que[l++];
    for (int i = h[u]; i; i = nxt[i])
      if (w[i] && !lv[to[i]]) {
        lv[to[i]] = lv[u] + 1;
        que[++r] = to[i];
      }
  }
  return lv[T] != 0;
}
int Flow(int u, int f) {
  if (u == T) return f;
  int d = 0, s = 0;
  for (int &i = iter[u]; i; i = nxt[i])
    if (w[i] && lv[to[i]] == lv[u] + 1) {
      d = Flow(to[i], std::min(f, w[i]));
      f -= d, s += d;
      w[i] -= d, w[i ^ 1] += d;
      if (!f) break;
    }
  return s;
}
inline int Dinic() {
  int Ans = 0;
  while (Lvl()) {
    for (int i = 1; i <= N; ++i) iter[i] = h[i];
    Ans += Flow(S, Inf);
  }
  return Ans;
}
}  // namespace DinicFlows
int n, m, k;
int a[1005], s[1005], b[1005];
int eu[1005], ev[1005];
std::vector<int> G[1005];
void TaskSolve();
int main() {
  int tests = 1;
  while (tests--) {
    TaskSolve();
  }
  return 0;
}
int id[1005], iid[1005], tmp[1005];
void Solve(int lb, int rb, int l, int r) {
  if (l > r) return;
  if (lb == rb) {
    for (int i = l; i <= (r); ++i) b[id[i]] = s[lb];
    return;
  }
  int mid = (lb + rb) >> 1;
  int len = r - l + 1;
  int lp = l, rp = r;
  {
    DinicFlows::Init(len + 2);
    for (int i = l; i <= (r); ++i)
      for (int &v : G[id[i]])
        if (l <= iid[v] && iid[v] <= r)
          DinicFlows::insw(i - l + 1, iid[v] - l + 1);
    for (int i = l; i <= (r); ++i) {
      if (a[id[i]] <= s[mid])
        DinicFlows::insw(0, i - l + 1, 1);
      else
        DinicFlows::insw(i - l + 1, 0, 1);
    }
    DinicFlows::Dinic();
  }
  for (int i = l; i <= (r); ++i)
    if (DinicFlows::lv[i - l + 1])
      tmp[lp++] = id[i];
    else
      tmp[rp--] = id[i];
  for (int i = l; i <= (r); ++i) iid[id[i] = tmp[i]] = i;
  Solve(lb, mid, l, rp);
  Solve(mid + 1, rb, lp, r);
}
void TaskSolve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= (n); ++i) scanf("%d", a + i), s[i] = a[i];
  sort(s + 1, s + n + 1);
  k = unique(s + 1, s + n + 1) - s - 1;
  for (int i = 1; i <= (m); ++i) {
    scanf("%d%d", &eu[i], &ev[i]);
    G[ev[i]].push_back(eu[i]);
  }
  for (int i = 1; i <= (n); ++i) iid[id[i] = i] = i;
  Solve(1, k, 1, n);
  for (int i = 1; i <= (n); ++i) printf("%d%c", b[i], " \n"[i == n]);
}
