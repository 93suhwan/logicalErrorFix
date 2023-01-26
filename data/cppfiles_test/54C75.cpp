#include <bits/stdc++.h>
using namespace std;
void dbg() { cout << "DEBUG\n"; }
const int INF = 1e9;
const long long LINF = 1e18;
const long long mod = 1e9 + 7;
const int maxn = 1e6 + 10;
struct G {
  int to, next, state, dir;
} edge[maxn];
int tot = 1, head[maxn];
void addEdge(int u, int v, string& str, int direct) {
  edge[tot].to = v;
  edge[tot].next = head[u];
  if (str[0] == 'c')
    edge[tot].state = 0;
  else
    edge[tot].state = 1;
  edge[tot].dir = direct;
  head[u] = tot++;
  return;
}
int n, m;
void init() {
  for (int i = 0; i <= n; i++) head[i] = 0;
  tot = 1;
  return;
}
void dfs(int cur, int status, int& res, vector<bool>& vis, vector<int>& color) {
  if (res == -1) return;
  if (status == 1 && res != -1) res++;
  color[cur] = status;
  vis[cur] = 1;
  for (int i = head[cur]; i; i = edge[i].next) {
    int x = edge[i].to;
    int next_status = edge[i].state;
    int direct = edge[i].dir;
    if (vis[x]) {
      if (direct == 0) {
        if (color[cur] == 0) {
          if (next_status == 0 && color[x] == 1)
            res = -1;
          else if (next_status == 1 && color[x] == 0)
            res = -1;
        } else {
          if (next_status == 0 && color[x] == 0)
            res = -1;
          else if (next_status == 1 && color[x] == 1)
            res = -1;
        }
      } else {
        if (color[x] == 0) {
          if (next_status == 0 && color[cur] == 1)
            res = -1;
          else if (next_status == 1 && color[cur] == 0)
            res = -1;
        } else {
          if (next_status == 0 && color[cur] == 0)
            res = -1;
          else if (next_status == 1 && color[cur] == 1)
            res = -1;
        }
      }
    } else {
      if (next_status == 0 && color[cur] == 0)
        dfs(x, color[cur], res, vis, color);
      else if (next_status == 0 && color[cur] == 1)
        dfs(x, color[cur], res, vis, color);
      else if (next_status == 1 && color[cur] == 0)
        dfs(x, color[cur] ^ 1, res, vis, color);
      else if (next_status == 1 && color[cur] == 1)
        dfs(x, color[cur] ^ 1, res, vis, color);
    }
    if (res == -1) return;
  }
  return;
}
void solve() {
  cin >> n >> m;
  init();
  for (int i = 0; i < m; i++) {
    int a, b;
    string str;
    cin >> a >> b >> str;
    addEdge(a, b, str, 0);
    addEdge(b, a, str, 1);
  }
  vector<bool> vis1(n + 1, false), vis2(n + 1, false);
  vector<int> color1(n + 1, -1), color2(n + 1, -1);
  ;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (vis1[i]) continue;
    int v1 = 0, v2 = 0;
    dfs(i, 0, v1, vis1, color1);
    dfs(i, 1, v2, vis2, color2);
    if (v1 == -1 && v2 == -1) {
      cout << "-1" << '\n';
      return;
    }
    ans += max(v1, v2);
  }
  cout << ans << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) solve();
  return 0;
}
