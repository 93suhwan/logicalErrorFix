#include <bits/stdc++.h>
using namespace std;
const int Inf = 0x3f3f3f3f;
mt19937_64 Rand(chrono::steady_clock::now().time_since_epoch().count());
long long inline rand(long long L, long long R) {
  return uniform_int_distribution<long long>(L, R)(Rand);
}
double inline frand() { return uniform_real_distribution<double>(0, 1)(Rand); }
struct UnionFind {
  int fa[55];
  void inline init() { memset(fa, -1, sizeof(fa)); }
  UnionFind() { init(); }
  int inline root(int x) { return fa[x] < 0 ? x : fa[x] = root(fa[x]); }
  bool inline conn(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return 0;
    if (fa[a] < fa[b]) swap(a, b);
    return fa[b] += fa[a], fa[a] = b, 1;
  }
} uf;
int N, K;
int d[10];
int w[55][55];
vector<pair<int, pair<int, int> > > egs;
bool sel[55][55];
int deg[55];
vector<pair<int, int> > vps;
bool bsel[55][55], nbsel[55][55];
int bdeg[55], nbdeg[55];
vector<pair<int, int> > bvps, nbvps;
;
int main() {
  scanf("%d%d", &N, &K);
  for (int i = 1; i <= (K); ++i) scanf("%d", d + i);
  for (int i = 1; i <= (N); ++i)
    for (int j = i + 1; j <= N; ++j)
      scanf("%d", w[i] + j), w[j][i] = w[i][j],
                             egs.push_back(make_pair(w[i][j], make_pair(i, j)));
  sort(egs.begin(), egs.end());
  uf.init();
  int res = 0, ans = Inf;
  for (int i = 0; i < (((int)(egs).size())); ++i) {
    int ww = egs[i].first;
    int u = egs[i].second.first, v = egs[i].second.second;
    if (u <= K && deg[u] == d[u]) continue;
    if (v <= K && deg[v] == d[v]) continue;
    if (uf.conn(u, v))
      sel[u][v] = 1, res += ww, vps.push_back(make_pair(u, v)), ++deg[u],
      ++deg[v];
  }
  ans = min(ans, res);
  memcpy(bsel, sel, sizeof(sel));
  memcpy(bdeg, deg, sizeof(deg));
  memcpy(nbsel, sel, sizeof(sel));
  memcpy(nbdeg, deg, sizeof(deg));
  int fans = res, fbans = res;
  bvps = vps;
  nbvps = vps;
  while (clock() < 5 * CLOCKS_PER_SEC) {
    memcpy(sel, nbsel, sizeof(sel));
    memcpy(deg, nbdeg, sizeof(deg));
    vps = nbvps;
    res = fbans;
    for (double tmp = 1; tmp > 1e-10; tmp *= .9999) {
      memcpy(sel, bsel, sizeof(sel));
      memcpy(deg, bdeg, sizeof(deg));
      vps = bvps;
      uf.init();
      res = fans;
      int br = rand(0, ((int)(vps).size()) - 1);
      --deg[vps[br].first];
      --deg[vps[br].second];
      sel[vps[br].first][vps[br].second] = 0;
      res -= w[vps[br].first][vps[br].second];
      vps.erase(vps.begin() + br);
      for (int i = 0; i < (((int)(vps).size())); ++i)
        uf.conn(vps[i].first, vps[i].second);
      while (1) {
        int u = rand(1, N), v = rand(1, N);
        if (u > v) swap(u, v);
        int ww = w[u][v];
        if (u == v) continue;
        if (sel[u][v]) continue;
        if (u <= K && deg[u] == d[u]) continue;
        if (v <= K && deg[v] == d[v]) continue;
        if (uf.conn(u, v)) {
          sel[u][v] = 1, res += ww, vps.push_back(make_pair(u, v)), ++deg[u],
          ++deg[v];
          break;
        }
      }
      if (exp((ans - res) / tmp) > frand()) {
        memcpy(bsel, sel, sizeof(sel));
        memcpy(bdeg, deg, sizeof(deg));
        bvps = vps;
        fans = res;
      }
      if (ans > res) {
        memcpy(nbsel, sel, sizeof(sel));
        memcpy(nbdeg, deg, sizeof(deg));
        nbvps = vps;
        fans = fbans = res;
      }
      ans = min(ans, res);
    }
  }
  printf("%d\n", ans);
  return 0;
}
