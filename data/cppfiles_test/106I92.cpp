#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && (c != '-')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
namespace MCMF {
const long long inf = 1e14;
const int N = 1e4 + 10, M = 2e5 + 10;
int tot, first[N], to[M << 1], last[M << 1], flow[M << 1];
long long cost[M << 1];
inline void init() { tot = -1, memset((first), (-1), sizeof(first)); }
inline void add(int x, int y, int w, long long f) {
  to[++tot] = y, flow[tot] = w, cost[tot] = f, last[tot] = first[x],
  first[x] = tot;
}
inline void Add(int x, int y, int w, long long f) {
  add(x, y, w, f), add(y, x, 0, -f);
}
long long dis[N], Flow[N];
int pre[N], pos[N];
bool vis[N];
inline bool spfa(int s, int t) {
  for (int i = (s); i <= (t); i++) vis[i] = 0, dis[i] = Flow[i] = inf;
  queue<int> q;
  q.push(s), dis[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop(), vis[u] = 0;
    for (int i = first[u]; i != -1; i = last[i]) {
      int v = to[i];
      if (dis[u] + cost[i] < dis[v] && flow[i]) {
        dis[v] = dis[u] + cost[i], Flow[v] = min(Flow[u], (long long)flow[i]),
        pre[v] = u, pos[v] = i;
        if (!vis[v]) q.push(v), vis[v] = 1;
      }
    }
  }
  return dis[t] != inf;
}
long long MaxFlow, MinCost;
inline void solve(int s, int t, int k) {
  while (spfa(s, t)) {
    if (MaxFlow + Flow[t] > k) {
      MinCost += dis[t] * (k - MaxFlow);
      return;
    }
    MaxFlow += Flow[t], MinCost += Flow[t] * dis[t];
    for (int i = t; i != s; i = pre[i])
      flow[pos[i]] -= Flow[t], flow[pos[i] ^ 1] += Flow[t];
  }
}
}  // namespace MCMF
const int N = 1 << 20 | 10;
int n, m, a[N], id[N], flag[N];
pair<int, int> b[N];
vector<pair<int, int> > v[N << 1];
int main() {
  MCMF::init();
  n = read(), m = read();
  for (int i = (0); i < (1 << n); i++) a[i] = read();
  int S = 1, tot = 1, cnt = 0, cntb = 0;
  for (int i = (0); i < (1 << n); i++)
    if (__builtin_popcount(i) & 1) b[++cntb] = make_pair(a[i], i);
  sort(b + 1, b + 1 + cntb), reverse(b + 1, b + 1 + cntb);
  for (int i = (1); i <= (min(cntb, 400)); i++)
    id[b[i].second] = ++tot, MCMF::Add(S, tot, 1, 0);
  cntb = 0;
  for (int i = (0); i < (1 << n); i++)
    if (!(__builtin_popcount(i) & 1)) b[++cntb] = make_pair(a[i], i);
  sort(b + 1, b + 1 + cntb), reverse(b + 1, b + 1 + cntb);
  for (int i = (1); i <= (min(cntb, 400)); i++)
    id[b[i].second] = ++tot, flag[tot] = 1;
  for (int i = (0); i < (1 << n); i++)
    if (__builtin_popcount(i) & 1)
      for (int j = (0); j < (n); j++) {
        int k = a[i ^ (1 << j)] + a[i];
        v[k].emplace_back(i, i ^ (1 << j));
      }
  for (int i = (2e6); i >= (0); i--) {
    for (auto j : v[i])
      if (cnt <= 1000) {
        if (!id[j.first]) id[j.first] = ++tot, MCMF::Add(S, id[j.first], 1, 0);
        if (!id[j.second]) id[j.second] = ++tot, flag[tot] = 1;
        ++cnt;
      }
  }
  for (int i = (0); i < (1 << n); i++)
    if (id[i] && __builtin_popcount(i) & 1) {
      for (int j = (0); j < (n); j++)
        if (id[i ^ (1 << j)])
          MCMF::Add(id[i], id[i ^ (1 << j)], 1, -a[i] - a[i ^ (1 << j)]);
    }
  int T = ++tot;
  for (int i = (1); i <= (tot); i++)
    if (flag[i]) MCMF::Add(i, T, 1, 0);
  MCMF::solve(S, T, m);
  printf("%lld\n", -MCMF::MinCost);
}
