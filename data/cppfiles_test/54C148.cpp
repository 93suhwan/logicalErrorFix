#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
bool vis[N];
long long col[N];
long long cnt_cur[2] = {0};
vector<pair<long long, bool>> adj[N];
bool possible = true;
void dfs(long long v, long long c) {
  col[v] = c;
  cnt_cur[c]++;
  vis[v] = 1;
  for (auto &i : adj[v]) {
    long long want = c ^ i.second;
    if (vis[i.first]) {
      if (col[i.first] != want) {
        possible = false;
        return;
      }
    } else {
      dfs(i.first, want);
    }
  }
}
int32_t main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    possible = true;
    for (long long i = 1; i <= n; i++) adj[i].clear(), vis[i] = false;
    for (long long i = 0; i < m; i++) {
      long long a, b;
      cin >> a >> b;
      string s;
      cin >> s;
      if (s == "crewmate")
        adj[a].push_back({b, 0}), adj[b].push_back({a, 0});
      else
        adj[a].push_back({b, 1}), adj[b].push_back({a, 1});
    }
    long long cnt[2];
    cnt[0] = cnt[1] = 0;
    for (long long i = 1; i <= n; i++) {
      if (vis[i]) continue;
      cnt_cur[0] = cnt_cur[1] = 0;
      dfs(i, 0);
      if (!possible) break;
      if (cnt_cur[0] < cnt_cur[1]) swap(cnt_cur[0], cnt_cur[1]);
      cnt[0] += cnt_cur[0];
      cnt[1] += cnt_cur[1];
    }
    if (!possible) {
      cout << -1 << '\n';
    } else
      cout << cnt[0] << '\n';
  }
}
