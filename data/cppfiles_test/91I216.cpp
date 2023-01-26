#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 1E5 + 100;
const long long INF = 1E9 + 100;
class Edge {
 public:
  long long u, v, w;
};
long long n, m, q, k;
Edge e[MAX_N << 1];
bool vis[MAX_N << 1];
class cmp {
 public:
  bool operator()(const long long& a, const long long& b) {
    return e[a].w > e[b].w;
  }
};
priority_queue<long long, vector<long long>, cmp> que[MAX_N], totQue;
map<long long, long long> G[MAX_N];
long long topM[MAX_N][3];
class cmp2 {
 public:
  bool operator()(const pair<long long, long long>& a,
                  const pair<long long, long long>& b) {
    return a.second > b.second;
  }
};
priority_queue<pair<long long, long long>, vector<pair<long long, long long> >,
               cmp2>
    points;
void update(long long u) {
  for (long long i = 0; i <= 2; ++i) {
    if (vis[topM[u][i]]) {
      for (long long j = i + 1; j <= 2; ++j) {
        topM[u][j - 1] = topM[u][j];
      }
      topM[u][2] = 0;
      break;
    }
  }
  while (!que[u].empty() && vis[que[u].top()]) que[u].pop();
  long long uk = que[u].top();
  for (long long i = 0; i <= 2; ++i)
    if (e[uk].w < e[topM[u][i]].w) swap(uk, topM[u][i]);
  if (uk != que[u].top()) {
    totQue.push(que[u].top());
  }
  que[u].pop();
  if (uk) que[u].push(uk);
  points.emplace(u, e[topM[u][0]].w + e[topM[u][1]].w + e[topM[u][2]].w);
}
void push(long long u, long long k) {
  que[u].push(k);
  update(u);
}
void push(long long k) {
  push(e[k].u, k);
  push(e[k].v, k);
  G[e[k].u][e[k].v] = G[e[k].v][e[k].u] = k;
}
void cut(long long u, long long v) {
  vis[G[u][v]] = true;
  update(u);
  update(v);
}
pair<long long, long long> getMaxPoint() {
  while (points.top().second != e[topM[points.top().first][0]].w +
                                    e[topM[points.top().first][1]].w +
                                    e[topM[points.top().first][2]].w)
    points.pop();
  return points.top();
}
bool check(long long k1, long long k2) {
  return e[k1].u == e[k2].u || e[k1].u == e[k2].v || e[k1].v == e[k2].u ||
         e[k1].v == e[k2].v;
}
long long eBuf[MAX_N];
pair<long long, long long> getMinEdge() {
  while (!totQue.empty() && vis[totQue.top()]) totQue.pop();
  long long miK = totQue.top();
  eBuf[0] = 0;
  totQue.pop();
  while (true) {
    while (!totQue.empty() && vis[totQue.top()]) totQue.pop();
    if (totQue.empty()) break;
    if (check(totQue.top(), miK)) {
      eBuf[++eBuf[0]] = totQue.top();
      totQue.pop();
    } else {
      break;
    }
  }
  pair<long long, long long> ret;
  if (totQue.empty())
    ret = pair<long long, long long>(miK, 0);
  else
    ret = pair<long long, long long>(miK, totQue.top());
  for (long long i = 1; i <= eBuf[0]; ++i) totQue.push(eBuf[i]);
  totQue.push(miK);
  return ret;
}
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  e[0].w = INF;
  for (long long i = 1; i <= n; ++i) {
    k += 1;
    cin >> e[k].u >> e[k].v >> e[k].w;
    push(k);
  }
  long long u, v, ans = getMaxPoint().second;
  pair<long long, long long> miE = getMinEdge();
  ans = min(ans, e[miE.first].w + e[miE.second].w);
  u = e[miE.first].u;
  v = e[miE.first].v;
  ans = min(ans, e[topM[u][1]].w + e[topM[v][1]].w);
  cout << ans << '\n';
  cin >> q;
  while (q--) {
    long long opt, u, v, w;
    cin >> opt >> u >> v;
    if (opt) {
      cin >> w;
      k += 1;
      e[k].u = u;
      e[k].v = v;
      e[k].w = w;
      push(k);
    } else {
      cut(u, v);
    }
    long long ans = getMaxPoint().second;
    pair<long long, long long> miE = getMinEdge();
    ans = min(ans, e[miE.first].w + e[miE.second].w);
    u = e[miE.first].u;
    v = e[miE.first].v;
    ans = min(ans, e[topM[u][1]].w + e[topM[v][1]].w);
    cout << ans << '\n';
  }
  cout << endl;
  return 0;
}
