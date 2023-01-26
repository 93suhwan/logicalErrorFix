#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
const int M = 1000010;
vector<int> g[N];
int n, q, sp[M], tot, primeID[M], primes[N], a[N], comp[N], totComps;
void dfs(int u) {
  comp[u] = totComps;
  for (int v : g[u])
    if (!comp[v]) dfs(v);
}
int main() {
  for (int i = 2; i * i < M; ++i)
    if (!sp[i]) {
      sp[i] = i;
      for (int j = i * i; j < M; j += i) {
        if (!sp[j]) sp[j] = i;
      }
    }
  for (int i = 2; i < M; ++i) {
    if (!sp[i]) sp[i] = i;
    if (sp[i] == i) primes[++tot] = i, primeID[i] = tot;
  }
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    int x = a[i], u = tot + i;
    while (sp[x] > 1) {
      int p = sp[x];
      while (x % p == 0) x /= p;
      int v = primeID[p];
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
  }
  for (int i = 1; i <= tot + n; ++i)
    if (!comp[i]) {
      ++totComps;
      dfs(i);
    }
  set<pair<int, int>> good;
  for (int i = 1; i <= n; ++i) {
    int x = a[i], y = a[i] + 1;
    vector<int> one, two;
    while (sp[x] > 1) {
      int p = sp[x];
      while (x % p == 0) x /= p;
      int v = comp[primeID[p]];
      one.emplace_back(v);
    }
    while (sp[y] > 1) {
      int p = sp[y];
      while (y % p == 0) y /= p;
      int v = comp[primeID[p]];
      two.emplace_back(v);
    }
    for (int u : one)
      for (int v : two) {
        if (u == v) continue;
        if (u > v) swap(u, v);
        good.emplace(u, v);
      }
    for (int u : two)
      for (int v : two) {
        if (u == v) continue;
        if (u > v) swap(u, v);
        good.emplace(u, v);
      }
  }
  while (q--) {
    int s, t;
    scanf("%d %d", &s, &t);
    int u = comp[tot + s], v = comp[tot + t];
    if (u == v) {
      puts("0");
      continue;
    }
    if ((~a[s] & 1) or (~a[t] & 1)) {
      puts("1");
      continue;
    }
    if (u > v) swap(u, v);
    puts(good.count(make_pair(u, v)) ? "1" : "2");
  }
  return 0;
}
