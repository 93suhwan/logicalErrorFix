#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const long long P = 998244353;
const long long N = 60;
long long n, k, sum;
long long mx[N], d[N], w[N][N], fa[N];
vector<pair<long long, long long> > e;
long long getfa(long long x) { return (fa[x] == x) ? x : fa[x] = getfa(fa[x]); }
signed main() {
  srand(time(NULL));
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
  for (double T = 100000; T >= 0.00001; T *= 0.999996) {
    long long x = rand() % e.size();
    d[e[x].first]--;
    d[e[x].second]--;
    for (long long i = 1; i <= n; i++) fa[i] = i;
    for (long long i = 0; i < e.size(); i++)
      if (i != x) fa[getfa(e[i].first)] = getfa(e[i].second);
    long long nw = sum - w[e[x].first][e[x].second];
    long long u = rand() % (n - 1) + 1;
    long long v = rand() % (n - u) + u + 1;
    while (getfa(u) == getfa(v) || mx[u] == d[u] || mx[v] == d[v]) {
      u = rand() % (n - 1) + 1;
      v = rand() % (n - u) + u + 1;
    }
    nw += w[u][v];
    if (exp(-(double)(nw - sum) / T) >= (double)rand() / RAND_MAX) {
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
