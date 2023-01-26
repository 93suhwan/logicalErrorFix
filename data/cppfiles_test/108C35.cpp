#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  short f = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar())
    x = (x << 1) + (x << 3) + (c ^ 48);
  x *= f;
  return;
}
const int N = 4e5 + 5, K = 21;
int T, n;
int a[N], b[N];
vector<int> g[N];
struct node {
  int a, b, id;
} s[N];
bool vis[N];
void dfs(int u) {
  vis[u] = 1;
  for (int v : g[u])
    if (!vis[v]) dfs(v);
}
int main() {
  read(T);
  while (T--) {
    read(n);
    for (int i = 1; i <= n; ++i) g[i].clear(), vis[i] = 0;
    int maxx = 0, maxp;
    for (int i = 1; i <= n; ++i) read(a[i]), s[i].a = a[i], s[i].id = i;
    for (int i = 1; i <= n; ++i) read(b[i]), s[i].b = b[i];
    sort(s + 1, s + n + 1, [&](node a, node b) { return a.a < b.a; });
    for (int i = 2; i <= n; ++i) g[s[i - 1].id].push_back(s[i].id);
    sort(s + 1, s + n + 1, [&](node a, node b) { return a.b < b.b; });
    for (int i = 2; i <= n; ++i) g[s[i - 1].id].push_back(s[i].id);
    for (int i = 1; i <= n; ++i)
      if (a[i] > maxx) maxx = a[i], maxp = i;
    dfs(maxp);
    for (int i = 1; i <= n; ++i) putchar(vis[i] + '0');
    puts("");
  }
  return 0;
}
