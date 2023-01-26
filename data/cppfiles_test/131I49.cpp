#include <bits/stdc++.h>
using namespace std;
const int maxn = 60 * 100000 + 10, maxm = maxn * 2;
int h[maxn], e[maxm], ne[maxm], idx = 0;
unordered_map<int, int> ps;
int cnt = 0;
bool vis[maxn];
void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
  e[idx] = a, ne[idx] = h[b], h[b] = idx++;
}
void solve() {
  memset(h, -1, sizeof h);
  int n;
  std::cin >> n;
  cnt = n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= (int)(n); i++) std::cin >> a[i], ps[a[i]] = i;
  for (int i = 1; i <= (int)(n); i++) {
    while (a[i]) {
      long long lg = 31 - __builtin_clz(a[i]), x = 1 << lg, nxt;
      if (x < a[i]) x <<= 1;
      nxt = x - a[i];
      if (!ps[nxt]) ps[nxt] = ++cnt;
      add(ps[a[i]], ps[nxt]);
      a[i] = nxt;
    }
  }
  std::vector<int> dep(n * 30 + 1, 0);
  memset(vis, 0, sizeof vis);
  function<void(int u, int fa)> dfs = [&](int u, int fa) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int i = h[u]; ~i; i = ne[i]) {
      int j = e[i];
      if (j == fa) continue;
      dep[j] = dep[u] + 1;
      dfs(j, u);
    }
  };
  dfs(1, 0);
  int s = std::max_element(dep.begin(), dep.end()) - dep.begin();
  dep[s] = 0;
  dfs(s, 0);
  int e = std::max_element(dep.begin(), dep.end()) - dep.begin();
  std::cout << s + 1 << " " << e + 1 << " " << dep[e] << "\n";
  return;
}
int main() { solve(); }
