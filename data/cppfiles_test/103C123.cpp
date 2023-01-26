#include <bits/stdc++.h>
constexpr const unsigned int maxn = 2005u;
constexpr const unsigned int maxl = maxn * maxn;
char s[maxn];
unsigned int nxt[maxl], ans[maxl], dfn[maxl], tim;
void dfs(unsigned int u) {
  dfn[u] = ++tim;
  if (!dfn[nxt[u]]) {
    dfs(nxt[u]);
  } else if (ans[nxt[u]] == -1u) {
    ans[u] = dfn[u] - dfn[nxt[u]];
    for (unsigned int v = nxt[u]; v != u; v = nxt[v]) {
      ans[v] = ans[u];
    }
  }
  if (ans[u] == -1u) {
    ans[u] = ans[nxt[u]] + 1;
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  unsigned int T;
  std::cin >> T;
  for (unsigned int cas = 1; cas <= T; ++cas) {
    unsigned int n, m;
    std::cin >> n >> m;
    unsigned int l = n * m;
    std::iota(nxt, nxt + l, 0u);
    std::memset(dfn, 0, sizeof(unsigned int) * l);
    std::memset(ans, -1, sizeof(unsigned int) * l);
    for (unsigned int i = 0; i != n; ++i) {
      std::cin >> s;
      for (unsigned int j = 0, k = i * m; j != m; ++j, ++k) {
        if (s[j] == 'U' && i) {
          nxt[k] -= m;
        }
        if (s[j] == 'D' && i + 1 != n) {
          nxt[k] += m;
        }
        if (s[j] == 'L' && j) {
          --nxt[k];
        }
        if (s[j] == 'R' && j + 1 != m) {
          ++nxt[k];
        }
      }
    }
    unsigned int x = 0, y = 0, d = 0;
    tim = 0;
    for (unsigned int u = 0; u != l; ++u) {
      if (!dfn[u]) {
        dfs(u);
        if (ans[u] > d) {
          x = u / m;
          y = u % m;
          d = ans[u];
        }
      }
    }
    std::cout << x + 1 << ' ' << y + 1 << ' ' << d + 1 << '\n';
  }
  return 0;
}
