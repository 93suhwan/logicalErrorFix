#include <bits/stdc++.h>
template <class T>
inline T max(const T &x, const T &y) {
  return x > y ? x : y;
}
template <class T>
inline T min(const T &x, const T &y) {
  return x < y ? x : y;
}
template <class T>
inline bool chkmax(T &x, const T &y) {
  return x < y ? x = y, true : false;
}
template <class T>
inline bool chkmin(T &x, const T &y) {
  return x > y ? x = y, true : false;
}
inline int read() {
  register int x = 0, v = 1;
  register char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') v = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * v;
}
const int MAXN = 3e5;
int n, m, Q;
int deg[MAXN | 1], dep[MAXN | 1], par[MAXN | 1], a[MAXN | 1], b[MAXN | 1];
std::vector<int> e[MAXN | 1];
bool vis[MAXN | 1];
void dfs(int x, int fa) {
  vis[x] = 1;
  par[x] = fa;
  dep[x] = dep[fa] + 1;
  for (int to : e[x]) {
    if (to == fa || vis[to]) continue;
    dfs(to, x);
  }
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= m; ++i) {
    int u = read(), v = read();
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1, 0);
  Q = read();
  for (int i = 1; i <= Q; ++i) {
    a[i] = read();
    b[i] = read();
    ++deg[a[i]];
    ++deg[b[i]];
  }
  int tot = 0;
  for (int i = 1; i <= n; ++i) tot += deg[i] % 2;
  if (tot) {
    puts("NO");
    printf("%d\n", tot / 2);
    return 0;
  }
  puts("YES");
  for (int i = 1; i <= Q; ++i) {
    int u = a[i], v = b[i];
    bool flag = false;
    static std::vector<int> ans1, ans2;
    ans1.clear();
    ans2.clear();
    if (dep[u] < dep[v]) {
      std::swap(u, v);
      flag = true;
    }
    while (dep[u] > dep[v]) ans1.push_back(u), u = par[u];
    while (u != v) {
      ans1.push_back(u);
      ans2.push_back(v);
      u = par[u];
      v = par[v];
    }
    ans1.push_back(u);
    std::reverse(ans2.begin(), ans2.end());
    for (int i : ans2) ans1.push_back(i);
    if (flag) std::reverse(ans1.begin(), ans1.end());
    printf("%d\n", (int)ans1.size());
    for (int i : ans1) printf("%d ", i);
    printf("\n");
  }
  return 0;
}
