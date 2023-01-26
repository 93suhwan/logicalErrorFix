#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int P = 998244353;
const int N = 60;
int n, k, sum, ans = INF, st;
int mx[N], d[N], w[N][N], fa[N];
mt19937 Rand(time(NULL));
vector<pair<int, int> > e;
int getfa(int x) { return (fa[x] == x) ? x : fa[x] = getfa(fa[x]); }
void anneal() {
  for (double T = 100000.0; T >= 1e-5; T *= 0.99996) {
    int x = Rand() % e.size();
    d[e[x].first]--;
    d[e[x].second]--;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 0; i < e.size(); i++)
      if (i != x) fa[getfa(e[i].first)] = getfa(e[i].second);
    int nw = sum - w[e[x].first][e[x].second];
    int u = Rand() % (n - 1) + 1;
    int v = Rand() % (n - u) + u + 1;
    while (getfa(u) == getfa(v) || mx[u] == d[u] || mx[v] == d[v]) {
      u = Rand() % (n - 1) + 1;
      v = Rand() % (n - u) + u + 1;
    }
    nw += w[u][v];
    if (exp(-(double)(nw - sum) / T) >= (double)Rand() / RAND_MAX) {
      sum = nw;
      e.erase(e.begin() + x);
      d[u]++;
      d[v]++;
      e.push_back({u, v});
    } else {
      d[e[x].first]++;
      d[e[x].second]++;
    }
    if ((double)(clock() - st) / CLOCKS_PER_SEC >= 5.8) break;
  }
  ans = min(ans, sum);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= k; i++) cin >> mx[i];
  for (int i = k + 1; i <= n; i++) mx[i] = INF;
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++) cin >> w[i][j];
  for (int i = 1; i < n; i++) {
    e.push_back({i, n});
    d[i]++;
    d[n]++;
    sum += w[i][n];
  }
  int st = clock();
  do anneal();
  while ((double)(clock() - st) / CLOCKS_PER_SEC < 5.8);
  cout << ans << '\n';
  return 0;
}
