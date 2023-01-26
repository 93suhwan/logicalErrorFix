#include <bits/stdc++.h>
using namespace std;
int ar[205];
char ch[205];
int n, m, ii, k;
long long fact[205], inv[205];
long long bigmod(long long e, long long x) {
  if (!x) return 1;
  long long p = bigmod(e, x / 2);
  p = (p * p) % 1000000007;
  if (x % 2) p = (p * e) % 1000000007;
  return p;
}
void fact_cal() {
  fact[0] = 1;
  inv[0] = 1;
  for (int i = 1; i <= 205 - 3; i++) {
    fact[i] = (fact[i - 1] * i) % 1000000007;
  }
  inv[205 - 3] = bigmod(fact[205 - 3], 1000000007 - 2);
  for (int i = 205 - 4; i >= 1; i--)
    inv[i] = (inv[i + 1] * (i + 1)) % 1000000007;
}
long long nCr(int nn, int r) {
  if (nn < r) return 0;
  long long re = fact[nn];
  re = re * (inv[r] * inv[nn - r] % 1000000007) % 1000000007;
  return re;
}
int add(int a, int b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
  return a;
}
vector<int> g[105];
int dist[105][105];
void dfs(int u, int p = -1) {
  dist[u][0]++;
  for (int v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    for (int i = 0; i <= n; i++) {
      dist[u][i + 1] += dist[v][i];
    }
  }
}
void solve() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int re = 0;
  for (int i = 1; i <= n; i++) {
    memset(dist, 0, sizeof(dist));
    dfs(i);
    for (int j = 0; j <= n + 2; j++) {
      long long gun = 1;
      int nn = 0;
      for (int v : g[i]) {
        if (dist[v][j]) {
          nn++;
          gun = gun * dist[v][j] % 1000000007;
        }
      }
      gun = nCr(nn, k) * gun % 1000000007;
      re = add(re, gun);
    }
  }
  if (k == 2) {
    printf("%lld\n", nCr(n, 2));
  } else
    printf("%d\n", re);
  for (int i = 1; i <= n; i++) g[i].clear();
}
int main() {
  int t = 1;
  fact_cal();
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
