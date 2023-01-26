#include <bits/stdc++.h>
using namespace std;
const int maxn = 55, maxm = 1250, inf = 2e9;
int n, K, m, N, D[maxn], w[maxn][maxn], id[maxn][maxn], wei[maxm];
int C[maxn], fa[maxn], dis[maxm], ce[maxm], pre[maxm];
int dd[maxm][2], ans = inf;
bool in[maxn][maxn], inq[maxm];
pair<int, int> E[maxn], F[maxn];
vector<int> G[maxm];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void brute(int x, int y) {
  if (x > K) {
    for (int i = int(1); i <= int(K); i++) fa[i] = i;
    for (int i = int(1); i <= int(K); i++) C[i] = 0;
    for (int i = int(1); i <= int(m); i++) {
      int x = E[i].first;
      int y = E[i].second;
      if (++C[x] > D[x]) return;
      if (++C[y] > D[y]) return;
      x = find(x);
      y = find(y);
      if (x == y) return;
      fa[x] = y;
    }
    memset(in, 0, sizeof(in));
    int s = 0;
    for (int i = int(1); i <= int(m); i++) s += w[E[i].first][E[i].second];
    while (1) {
      if (s >= ans) return;
      int r = 0;
      for (int i = int(1); i <= int(m); i++) F[i] = E[i];
      for (int i = int(1); i <= int(n); i++)
        for (int j = int(max(K, i) + 1); j <= int(n); j++)
          if (in[i][j]) F[(++r) + m] = {i, j};
      for (int i = int(1); i <= int(N); i++) G[i].clear();
      for (int i = int(m + 1); i <= int(m + r); i++) {
        iota(fa + 1, fa + n + 1, 1);
        fill(C + 1, C + n + 1, 0);
        for (int j = int(1); j <= int(m + r); j++)
          if (j != i) {
            int x = F[j].first, y = F[j].second;
            C[x]++, C[y]++, fa[find(x)] = find(y);
          }
        int I = id[F[i].first][F[i].second];
        wei[I] = -w[F[i].first][F[i].second];
        for (int i = int(1); i <= int(n); i++)
          for (int j = int(max(K, i) + 1); j <= int(n); j++)
            if (!in[i][j]) {
              if (C[i] < D[i]) G[id[i][j]].push_back(I);
              if (find(i) != find(j)) G[I].push_back(id[i][j]);
            }
      }
      for (int i = int(1); i <= int(n); i++)
        for (int j = int(max(K, i) + 1); j <= int(n); j++)
          if (!in[i][j]) {
            wei[id[i][j]] = w[i][j];
          }
      iota(fa + 1, fa + n + 1, 1);
      fill(C + 1, C + n + 1, 0);
      for (int i = int(1); i <= int(m + r); i++) {
        int x = F[i].first, y = F[i].second;
        C[x]++, C[y]++, fa[find(x)] = find(y);
      }
      for (int i = int(1); i <= int(N); i++)
        dis[i] = inf, ce[i] = 0, pre[i] = 0;
      queue<int> Q;
      for (int i = int(1); i <= int(n); i++)
        for (int j = int(max(K, i) + 1); j <= int(n); j++)
          if (!in[i][j]) {
            if (find(i) != find(j)) {
              dis[id[i][j]] = w[i][j], Q.push(id[i][j]), inq[id[i][j]] = 1;
            }
          }
      while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v : G[u])
          if (dis[v] > dis[u] + wei[v] ||
              (dis[v] == dis[u] + wei[v] && ce[v] > ce[u] + 1)) {
            pre[v] = u, dis[v] = dis[u] + wei[v], ce[v] = ce[u] + 1;
            if (!inq[v]) Q.push(v);
          }
        inq[u] = 0;
      }
      int _dis = inf, _ce = 0, x = 0;
      for (int i = int(1); i <= int(n); i++)
        for (int j = int(max(K, i) + 1); j <= int(n); j++)
          if (!in[i][j]) {
            if (C[i] < D[i] &&
                (_dis > dis[id[i][j]] ||
                 (_dis == dis[id[i][j]] && _ce > ce[id[i][j]]))) {
              x = id[i][j], _dis = dis[id[i][j]], _ce = ce[id[i][j]];
            }
          }
      if (!x) {
        if (m + r == n - 1) {
          ans = s;
        }
        return;
      }
      while (x) {
        in[dd[x][0]][dd[x][1]] ^= 1;
        s += wei[x];
        x = pre[x];
      }
    }
  }
  if (y > K) {
    brute(x + 1, x + 2);
    return;
  }
  brute(x, y + 1);
  E[++m] = {x, y}, brute(x, y + 1), --m;
}
int main() {
  scanf("%d %d", &n, &K);
  for (int i = int(1); i <= int(K); i++) {
    scanf("%d", &D[i]);
  }
  for (int i = int(K + 1); i <= int(n); i++) D[i] = n;
  for (int i = int(1); i <= int(n); i++)
    for (int j = int(i + 1); j <= int(n); j++) {
      id[i][j] = ++N;
      dd[N][0] = i, dd[N][1] = j;
      scanf("%d", &w[i][j]);
    }
  brute(1, 2);
  printf("%d\n", ans);
  return 0;
}
