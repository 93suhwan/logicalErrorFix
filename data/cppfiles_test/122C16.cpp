#include <bits/stdc++.h>
using namespace std;
const int N = 200050;
int f[N << 1], vis[N << 1], a[N];
void init(int n) {
  for (int i = 1; i <= n; ++i) f[i] = i, vis[i] = -1;
}
int find(int x) { return f[x] == x ? x : (f[x] = find(f[x])); }
void unite(int x, int y) { f[find(x)] = find(y); }
struct Edge {
  int x, y, z;
} E[N];
vector<int> e[N];
int popcnt(int x) {
  if (x == -1) return -1;
  int cnt = 0;
  for (int i = 0; i < 30; ++i) cnt ^= x >> i & 1;
  return cnt;
}
int n, m;
void dfs(int x, int fa) {
  if (vis[find(x)] == -1) {
    vis[find(x)] = 0;
    vis[find(x + n)] = 1;
  }
  a[x] = vis[find(x)];
  for (auto v : e[x])
    if (v != fa) dfs(v, x);
}
int main() {
  int T;
  ios::sync_with_stdio(false);
  for (cin >> T; T--;) {
    cin >> n >> m;
    init(n << 1);
    for (int i = 1; i <= n; ++i) e[i].clear();
    for (int i = 1; i < n; ++i) {
      cin >> E[i].x >> E[i].y >> E[i].z;
      if (E[i].z != -1) {
        if (popcnt(E[i].z)) {
          unite(E[i].x, E[i].y + n);
          unite(E[i].y, E[i].x + n);
        } else {
          unite(E[i].x, E[i].y);
          unite(E[i].x + n, E[i].y + n);
        }
      }
      e[E[i].x].push_back(E[i].y);
      e[E[i].y].push_back(E[i].x);
    }
    for (int i = 1, x, y, z; i <= m; ++i) {
      cin >> x >> y >> z;
      if (z) {
        unite(x, y + n);
        unite(y, x + n);
      } else {
        unite(x, y);
        unite(x + n, y + n);
      }
    }
    bool flag = true;
    for (int i = 1; i <= n; ++i)
      if (find(i) == find(i + n)) {
        flag = false;
        break;
      }
    if (!flag) {
      puts("NO");
      continue;
    }
    puts("YES");
    dfs(1, 0);
    for (int i = 1; i < n; ++i)
      printf("%d %d %d\n", E[i].x, E[i].y,
             E[i].z == -1 ? a[E[i].x] ^ a[E[i].y] : E[i].z);
  }
  return 0;
}
