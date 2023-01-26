#include <bits/stdc++.h>
using namespace std;
bool valid;
long long ans;
void dfs(long long i, vector<pair<long long, long long>> adj[],
         long long colour[], long long c[]) {
  c[colour[i]]++;
  long long j, l = adj[i].size();
  for (j = 0; j < l; j++) {
    if (colour[adj[i][j].first] == -1) {
      colour[adj[i][j].first] = colour[i] ^ adj[i][j].second;
      dfs(adj[i][j].first, adj, colour, c);
    } else if (colour[adj[i][j].first] != colour[i] ^ adj[i][j].second) {
      valid = false;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n, m, i, j, c[2];
  string a;
  cin >> t;
  for (; t--;) {
    valid = true;
    ans = 0;
    c[0] = c[1] = 0;
    cin >> n >> m;
    long long colour[n + 1];
    for (i = 0; i <= n; i++) {
      colour[i] = -1;
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
      if (colour[i] == -1) {
        c[0] = c[1] = 0;
        colour[i] = 0;
        dfs(i, adj, colour, c);
        ans = ans + max(c[0], c[1]);
      }
    }
    if (valid == false) {
      ans = -1;
    }
    cout << ans << "\n";
  }
}
