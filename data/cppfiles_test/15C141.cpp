#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int T, mod = 1e9 + 7, n, k, deep[N], timer, sz;
long long ans, fact[N], mem[N][N], vis[N][N];
vector<int> adj[N], v;
map<int, int> mp[N];
void _clear() {
  ans = 0;
  for (int i = 1; i <= n; i++) adj[i].clear();
}
long long po(long long x, long long os) {
  if (os == 0) return 1;
  long long z = po(x, os / 2);
  if (os & 1) return z * z % mod * x % mod;
  return z * z % mod;
}
long long modInv(long long x) { return po(x, mod - 2); }
long long c(long long n, long long r) {
  return fact[n] * modInv(fact[r] * fact[n - r] % mod) % mod;
}
void dfs(int u, int v) {
  deep[u] = deep[v] + 1;
  mp[u][deep[u]]++;
  for (auto &x : adj[u])
    if (x != v) {
      dfs(x, u);
      for (auto &p : mp[x]) mp[u][p.first] += p.second;
    }
}
long long dp(int i, int k) {
  if (k == 0) return 1;
  if (i == sz) return 0;
  long long &ret = mem[i][k];
  if (vis[i][k] == timer) return ret;
  vis[i][k] = timer;
  return ret = (dp(i + 1, k) + dp(i + 1, k - 1) * v[i] % mod) % mod;
}
long long calc(int p) {
  deep[p] = 0;
  for (int i = 1; i <= n; i++) mp[i].clear();
  dfs(p, p);
  long long ret = 0;
  for (int i = 2; i <= n; i++) {
    int num = 0;
    v.clear();
    for (auto &x : adj[p])
      if (mp[x].find(i) != mp[x].end()) {
        num++;
        v.push_back(mp[x][i]);
      }
    if (num < k) continue;
    timer++;
    sz = (int)(v.size());
    ret = (ret + dp(0, k)) % mod;
  }
  return ret;
}
int main() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % mod;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k);
    _clear();
    for (int i = 1; i <= n - 1; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    if (k == 2) {
      printf("%lld\n", c(n, 2));
      continue;
    }
    for (int i = 1; i <= n; i++) ans = (ans + calc(i)) % mod;
    printf("%lld\n", ans);
  }
}
