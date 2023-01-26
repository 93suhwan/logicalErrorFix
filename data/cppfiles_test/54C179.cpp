#include <bits/stdc++.h>
using namespace std;
bool valid;
long long ans;
void dfs(long long i, vector<pair<long long, long long>> adj[],
         long long team[], long long count[]) {
  count[team[i]]++;
  long long j, l = adj[i].size();
  for (j = 0; j < l; j++) {
    if (team[adj[i][j].first] == -1) {
      team[adj[i][j].first] = team[i] ^ adj[i][j].second;
      dfs(adj[i][j].first, adj, team, count);
    } else if (team[adj[i][j].first] != team[i] ^ adj[i][j].second) {
      valid = false;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n, m, i, j, count[2];
  string a;
  cin >> t;
  for (; t--;) {
    valid = true;
    ans = 0;
    count[0] = count[1] = 0;
    cin >> n >> m;
    long long team[n + 1];
    for (i = 0; i <= n; i++) {
      team[i] = -1;
    }
    vector<pair<long long, long long>> adj[n + 1];
    for (; m--;) {
      cin >> i >> j >> a;
      if (a == "imposter") {
        adj[i].push_back({j, 1});
        adj[j].push_back({i, 1});
      } else {
        adj[i].push_back({j, 0});
        adj[j].push_back({i, 0});
      }
    }
    for (i = 1; i <= n; i++) {
      if (team[i] == -1) {
        count[0] = count[1] = 0;
        team[i] = 0;
        dfs(i, adj, team, count);
        ans = ans + max(count[0], count[1]);
      }
    }
    if (valid == false) {
      ans = -1;
    }
    cout << ans << "\n";
  }
}
