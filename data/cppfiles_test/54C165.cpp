#include <bits/stdc++.h>
using namespace std;
long long __gcd(long long a, long long b) {
  return (b == 0 ? a : __gcd(b, a % b));
}
const long long inf = 2e9;
const long long mod = 1e9 + 7;
const long long maxn = 2e5 + 100;
vector<pair<int, int>> to[maxn], from[maxn];
int vis[maxn], color[maxn];
void dfs(int u, int& cnt, vector<int>& vi, bool& ok) {
  for (auto& nex : to[u]) {
    int v = nex.first, w = nex.second;
    if (vis[v]) {
      if (color[u] == 1 && w == 1 && color[v] == 1) {
        ok = false;
        return;
      } else if (color[u] == 1 && w == 2 && color[v] == 2) {
        ok = false;
        return;
      } else if (color[u] == 2 && w == 1 && color[v] == 2) {
        ok = false;
        return;
      } else if (color[u] == 2 && w == 2 && color[v] == 1) {
        ok = false;
        return;
      }
      continue;
    }
    vis[v] = 1;
    if (color[u] == 1) {
      if (w == 1)
        color[v] = 2;
      else {
        ++cnt;
        color[v] = 1;
      }
    } else {
      if (w == 1) {
        ++cnt;
        color[v] = 1;
      } else
        color[v] = 2;
    }
    vi.push_back(v);
    dfs(v, cnt, vi, ok);
  }
  for (auto& nex : from[u]) {
    int v = nex.first, w = nex.second;
    if (vis[v]) {
      if (color[u] == 1 && w == 1 && color[v] == 1) {
        ok = false;
        return;
      } else if (color[u] == 1 && w == 2 && color[v] == 2) {
        ok = false;
        return;
      } else if (color[u] == 2 && w == 1 && color[v] == 2) {
        ok = false;
        return;
      } else if (color[u] == 2 && w == 2 && color[v] == 1) {
        ok = false;
        return;
      }
      continue;
    }
    vis[v] = 1;
    if (color[u] == 1) {
      if (w == 1)
        color[v] = 2;
      else {
        ++cnt;
        color[v] = 1;
      }
    } else {
      if (w == 1) {
        ++cnt;
        color[v] = 1;
      } else
        color[v] = 2;
    }
    vi.push_back(v);
    dfs(v, cnt, vi, ok);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long _;
  cin >> _;
  while (_--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      vis[i] = 0;
      to[i].clear();
      from[i].clear();
    }
    for (int i = 1; i <= m; ++i) {
      int u, v;
      string s;
      cin >> u >> v >> s;
      int w = 2;
      if (s[0] == 'i') w = 1;
      to[u].emplace_back(v, w);
      from[v].emplace_back(u, w);
    }
    int ans = 0;
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
      if (vis[i]) continue;
      vector<int> vi;
      vis[i] = 1;
      color[i] = 1;
      int cnt = 1;
      vi.push_back(i);
      dfs(i, cnt, vi, ok);
      if (!ok) break;
      for (auto& x : vi) {
        color[x] = 0;
        vis[x] = 0;
      }
      vis[i] = 1;
      color[i] = 2;
      vi.clear();
      int cnt2 = 0;
      dfs(i, cnt2, vi, ok);
      if (!ok) break;
      ans += max(cnt, cnt2);
    }
    if (!ok)
      cout << "-1\n";
    else
      cout << ans << "\n";
  }
}
