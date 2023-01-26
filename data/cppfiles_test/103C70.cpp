#include <bits/stdc++.h>
using namespace std;
long long n, m, k, hf;
bool g[50][50];
inline void addedge(long long from, long long to) {
  g[from][to] = g[to][from] = true;
}
long long makepair[50], ans;
long long chains[50][2], belong[50];
long long p[50], vis[50];
bool check(long long u) {
  if (u == hf + 1) {
    for (long long i = 1; i <= hf; i++) vis[i] = 0;
    return true;
  }
  for (long long i = 1; i <= hf; i++) {
    if (vis[i]) continue;
    if (u == 1) {
      if (!g[chains[i][0]][chains[i][1]]) continue;
    } else {
      if (g[chains[p[u - 1]][0]][chains[i][0]] &&
          g[chains[p[u - 1]][1]][chains[i][1]])
        ;
      else if (g[chains[p[u - 1]][0]][chains[i][1]] &&
               g[chains[p[u - 1]][1]][chains[i][0]])
        ;
      else
        continue;
    }
    p[u] = i, vis[i] = 1;
    if (check(u + 1)) return true;
    p[u] = 0, vis[i] = 0;
  }
  return false;
}
vector<vector<long long> > colors;
vector<long long> nowcolor;
void color(long long u, long long now) {
  if (u == hf + 1) {
    nowcolor[0] = now - 1;
    colors.push_back(nowcolor);
    return;
  }
  for (long long i = 1; i <= now; i++) {
    nowcolor[u] = i;
    color(u + 1, max(now, i + 1));
  }
}
unordered_map<long long, bool> mp;
long long fac[50];
inline void InitFac(long long n) {
  fac[0] = 1;
  for (long long i = 1; i <= n; i++) fac[i] = fac[i - 1] * i;
}
inline long long A(long long n, long long m) {
  return n < m ? 0 : fac[n] / fac[n - m];
}
void dfs(long long u, long long now) {
  while (u <= n && makepair[u]) u++;
  if (u == n + 1) {
    bool ok = check(1);
    if (!ok) return;
    for (auto vec : colors) {
      long long Hash = 0;
      for (long long i = 1; i <= n; i++)
        Hash = Hash * hf + (vec[belong[i]] - 1);
      if (!mp[Hash]) {
        mp[Hash] = 1;
        ans += A(k, vec[0]);
      }
    }
    return;
  }
  for (long long i = u + 1; i <= n; i++)
    if (!makepair[i]) {
      makepair[u] = i, makepair[i] = u;
      chains[now][0] = u, chains[now][1] = i;
      belong[u] = belong[i] = now;
      dfs(u + 1, now + 1);
      makepair[u] = makepair[i] = 0;
    }
}
signed main() {
  InitFac(15);
  scanf("%lld %lld %lld", &n, &m, &k);
  hf = n >> 1;
  while (m--) {
    long long u, v;
    scanf("%lld %lld", &u, &v);
    addedge(u, v);
  }
  memset(makepair, 0, sizeof(makepair));
  nowcolor.resize(50);
  color(1, 1);
  dfs(1, 1);
  printf("%lld\n", ans);
  return 0;
}
