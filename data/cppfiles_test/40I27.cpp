#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9, mod = 1e9 + 7;
const long long INF = 1e18;
const int N = 3e5 + 10;
int n, m, q;
vector<int> G[N];
int cnt[N], sum;
int a[N], b[N], idx[N];
bool vis[N];
vector<int> vec;
void dfs(int u, int fa) {
  if (vis[u]) return;
  vis[u] = true;
  vec.push_back(u);
  for (int v : G[u]) {
    if (v == fa) continue;
    dfs(v, u);
  }
}
int main() {
  memset(vis, 0, sizeof vis);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> a[i] >> b[i];
    cnt[a[i]]++;
    cnt[b[i]]++;
  }
  bool k = true;
  for (int i = 1; i <= n; i++) {
    sum += cnt[i] % 2;
    if (cnt[i] & 1) k = false;
  }
  if (!k) {
    cout << "NO\n" << sum / 2;
  } else {
    dfs(1, -1);
    for (int i = 0; i < n; i++) {
      idx[vec[i]] = i;
    }
    cout << "YES\n";
    for (int i = 1; i <= q; i++) {
      int u = idx[a[i]], v = idx[b[i]];
      if (u < v) {
        cout << v - u + 1 << '\n';
        for (int i = u; i <= v; i++) cout << vec[i] << " ";
        cout << '\n';
      } else {
        cout << u - v + 1 << '\n';
        for (int i = u; i >= v; i--) cout << vec[i] << " ";
        cout << '\n';
      }
    }
  }
  return 0;
}
