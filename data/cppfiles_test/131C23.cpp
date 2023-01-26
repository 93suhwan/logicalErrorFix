#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 30 * 100000 + 10 * 2, maxm = maxn * 4;
int h[maxn], e[maxm], ne[maxm], idx = 0, dep[maxn];
bool vis[maxn];
void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }
void dfs(int u, int fa) {
  if (vis[u]) return;
  vis[u] = 1;
  for (int i = h[u]; ~i; i = ne[i]) {
    int j = e[i];
    if (j == fa) continue;
    dep[j] = dep[u] + 1;
    dfs(j, u);
  }
}
void solve() {
  memset(h, -1, sizeof h);
  idx = 0;
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= (int)(n); i++) std::cin >> a[i];
  std::map<int, int> ps, sp;
  int cnt = 0;
  for (int i = 1; i <= (int)(n); i++) ps[a[i]] = i, sp[i] = a[i];
  cnt = n;
  for (int i = 1; i <= (int)(n); i++) {
    while (a[i]) {
      int l = __builtin_clz(a[i]);
      l = 31 - l;
      int x = 1 << l;
      if (x < a[i]) x <<= 1;
      int nxt = x - a[i];
      if (!ps.count(nxt)) {
        ps[nxt] = ++cnt;
        sp[cnt] = nxt;
      }
      add(ps[nxt], ps[a[i]]);
      add(ps[a[i]], ps[nxt]);
      a[i] = nxt;
    }
  }
  memset(vis, 0, sizeof vis);
  dfs(1, 1);
  int s = std::max_element(dep + 1, dep + 1 + n) - dep;
  dep[s] = 0;
  memset(vis, 0, sizeof vis);
  dfs(s, s);
  int e = std::max_element(dep + 1, dep + 1 + n) - dep;
  std::cout << s << " " << e << " " << dep[e] << "\n";
  return;
}
int main() { solve(); }
