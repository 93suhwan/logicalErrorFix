#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int maxn5 = 3e5 + 10;
const int maxnt = 1.2e6 + 10;
const int maxn3 = 1e3 + 10;
const int mod = 1e9 + 7;
const long long inf = 2e18;
int mark[maxn5];
vector<pair<int, bool>> adj[maxn5];
bool imp[maxn5];
inline int dfs(int v) {
  mark[v]++;
  int have = 0;
  for (auto [u, ty] : adj[v]) {
    if (mark[u] < mark[v]) {
      imp[u] = ty ^ imp[v];
      int get = dfs(u);
      if (get == -1)
        have = -1;
      else if (have > -1)
        have += get;
    } else if (imp[u] != (imp[v] ^ ty))
      have = -1;
  }
  if (have > -1 && imp[v]) have++;
  return have;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      string s;
      cin >> s;
      adj[a].push_back({b, s == "imposter"});
      adj[b].push_back({a, s == "imposter"});
    }
    fill(mark, mark + n + 10, 0);
    int ans = 0;
    bool re = true;
    for (int i = 0; i < n; i++)
      if (mark[i] == 0) {
        imp[i] = true;
        int ans1 = dfs(i);
        imp[i] = false;
        int ans2 = dfs(i);
        if (max(ans1, ans2) == -1) re = false;
        ans += max(ans1, ans2);
      }
    cout << (re ? ans : -1) << '\n';
  }
}
