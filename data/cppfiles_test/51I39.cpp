#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const long long P = 998244353;
const long long N = 60;
long long n, k, sum;
long long mx[N], d[N], w[N][N], fa[N];
vector<pair<long long, long long> > e;
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
long long getfa(long long x) { return (fa[x] == x) ? x : fa[x] = getfa(fa[x]); }
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (long long i = 1; i <= k; i++) cin >> mx[i];
  for (long long i = k + 1; i <= n; i++) mx[i] = INF;
  for (long long i = 1; i < n; i++)
    for (long long j = i + 1; j <= n; j++) cin >> w[i][j];
  for (long long i = 1; i < n; i++) {
    e.push_back({i, n});
    d[i]++;
    d[n]++;
    sum += w[i][n];
  }
  for (double T = 2000; T >= 1e-15; T *= 0.9999) {
    long long x = Rand() % e.size();
    d[e[x].first]--;
    d[e[x].second]--;
    for (long long i = 1; i <= n; i++) fa[i] = i;
    for (long long i = 0; i < e.size(); i++)
      if (i != x) fa[getfa(e[i].first)] = getfa(e[i].second);
    long long nw = sum - w[e[x].first][e[x].second];
    long long u = Rand() % (n - 1) + 1;
    long long v = Rand() % (n - u) + u + 1;
    while (getfa(u) == getfa(v) || mx[u] == d[u] || mx[v] == d[v]) {
      u = Rand() % (n - 1) + 1;
      v = Rand() % (n - u) + u + 1;
    }
    nw += w[u][v];
    if (exp(-(double)(nw - sum) / T) >=
        (double)(Rand() % 1000000000) / 1000000000) {
      sum = nw;
      e.erase(e.begin() + x);
      d[u]++;
      d[v]++;
      e.push_back({u, v});
    } else {
      d[e[x].first]++;
      d[e[x].second]++;
    }
  }
  cout << sum << '\n';
  return 0;
}
