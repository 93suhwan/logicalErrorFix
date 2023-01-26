#include <bits/stdc++.h>
using namespace std;
void printi(vector<int> t) {
  for (auto &x : t) cout << x;
  cout << '\n';
}
void printl(vector<long long> t) {
  for (auto &x : t) cout << x;
  cout << '\n';
}
const int INF = 1e9;
const long long LINF = 1e18;
const long long mod = 1e9 + 7;
const int maxn = 6e5 + 100;
struct G {
  int to, next, w;
} edge[maxn];
int tot = 1, head[maxn];
void addEdge(int u, int v) {
  edge[tot].w = 0, edge[tot].to = v, edge[tot].next = head[u], head[u] = tot++;
}
int Father[maxn];
int findFather(int x) {
  if (Father[x] == x) return x;
  return Father[x] = findFather(Father[x]);
}
void Union(int x, int y) {
  x = Father[x];
  y = Father[y];
  Father[y] = x;
  return;
}
int dep[maxn], fa[maxn];
void dfs(int cur, int pre) {
  dep[cur] = dep[pre] + 1;
  fa[cur] = pre;
  for (int i = head[cur]; i; i = edge[i].next) {
    int x = edge[i].to;
    if (x == pre) continue;
    dfs(x, cur);
  }
  return;
}
void dfs2(int cur, int pos, vector<int> &path) {
  if (pos < 0) return;
  for (int i = head[cur]; i; i = edge[i].next) {
    int x = edge[i].to;
    if (x != path[pos]) continue;
    edge[i].w ^= 1;
    dfs2(x, pos - 1, path);
  }
  return;
}
void dfs3(int cur, int pre, int &ans) {
  int cnt = 0;
  for (int i = head[cur]; i; i = edge[i].next) {
    int x = edge[i].to;
    if (x == pre) continue;
    dfs3(x, cur, ans);
    cnt += edge[i].w;
  }
  ans -= cnt / 2;
  if (cnt % 2 == 1) {
    bool check = false;
    for (int i = head[fa[cur]]; i; i = edge[i].next)
      if (edge[i].to == cur) {
        check = (edge[i].w != 0);
        break;
      }
    if (check) ans--;
  }
  return;
}
void solve() {
  int n, e;
  cin >> n >> e;
  for (int i = 0; i <= n; i++) Father[i] = i;
  for (int i = 0; i < e; i++) {
    int a, b;
    cin >> a >> b;
    if (findFather(a) != findFather(b)) {
      Union(a, b);
      addEdge(a, b);
      addEdge(b, a);
    }
  }
  dfs(1, 0);
  int q;
  cin >> q;
  vector<vector<int>> path(q);
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    int dep1 = dep[a], dep2 = dep[b];
    vector<int> t1(1, a), t2(1, b);
    while (a != b) {
      if (dep1 > dep2) {
        a = fa[a];
        dep1 = dep[a];
        if (a != b) t1.push_back(a);
      } else {
        b = fa[b];
        dep2 = dep[b];
        if (a != b) t2.push_back(b);
      }
    }
    if (t1.back() != a && t2.back() != a) t1.push_back(a);
    dfs2(a, t1.size() - 1 - (t1.back() == a), t1);
    dfs2(b, t2.size() - 1 - (t2.back() == a), t2);
    reverse(t2.begin(), t2.end());
    vector<int> t;
    for (auto &x : t1) t.push_back(x);
    for (auto &x : t2) t.push_back(x);
    path[i] = t;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = head[i]; j; j = edge[j].next) ans += edge[j].w;
  if (ans == 0) {
    cout << "YES" << '\n';
    for (auto &x : path) {
      cout << x.size() << '\n';
      for (auto &y : x) cout << y << " ";
      cout << '\n';
    }
    return;
  }
  dfs3(1, 0, ans);
  cout << "NO" << '\n';
  cout << ans << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
