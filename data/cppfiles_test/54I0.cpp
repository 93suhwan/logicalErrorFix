#include <bits/stdc++.h>
int mod = 1000000007;
using namespace std;
using namespace std;
int t, n, m;
vector<vector<pair<int, int> > > adj(200005);
int cnt, imp;
bool info[200005];
bool visited[200005];
bool res;
void dfs(int v) {
  visited[v] = true;
  cnt++;
  if (info[v] == false) imp++;
  vector<pair<int, int> >::iterator it = adj[v].begin();
  for (; it != adj[v].end(); it++) {
    int dcn = (info[v] && (*it).second) || (!info[v] && !(*it).second);
    if (!visited[(*it).first]) {
      info[(*it).first] = dcn;
      dfs((*it).first);
    } else {
      if (dcn != info[(*it).first]) res = true;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
      int a, b;
      string s;
      cin >> a >> b >> s;
      adj[a].push_back(make_pair(b, (s == "imposter" ? 0 : 1)));
    }
    int ans = 0;
    memset(visited, 0, sizeof(visited));
    memset(info, 0, sizeof(info));
    for (int i = 1; i <= n; i++) {
      if (visited[i] == false) {
        cnt = 0;
        imp = 0;
        res = false;
        dfs(i);
        if (res) break;
        ans += max(imp, cnt - imp);
      }
    }
    if (!res)
      cout << ans << '\n';
    else
      cout << -1 << '\n';
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
    }
  }
}
