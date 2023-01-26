#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const long long MOD = 998244353;
vector<vector<pair<long long, long long> > > adj;
int c[2];
int colour[700005];
bool ok;
int n;
void dfs(int idx) {
  c[colour[idx]] += (idx <= n);
  for (auto x : adj[idx]) {
    if (colour[x.first] == -1) {
      colour[x.first] = colour[idx] ^ x.second;
      dfs(x.first);
    } else if (colour[x.first] != (colour[idx] ^ x.second)) {
      ok = false;
    }
  }
}
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int m;
    cin >> n >> m;
    adj.assign(n + m + 5, vector<pair<long long, long long> >());
    for (int i = 0; i < n + m + 5; i++) {
      colour[i] = -1;
    }
    int fake = n + 1;
    for (int i = 0; i < m; i++) {
      int a, b;
      string c;
      cin >> a >> b >> c;
      if (c == "crewmate") {
        adj[a].push_back(pair<long long, long long>(fake, 1));
        adj[fake].push_back(pair<long long, long long>(a, 1));
        adj[fake].push_back(pair<long long, long long>(b, 1));
        adj[b].push_back(pair<long long, long long>(fake, 1));
        fake++;
      } else {
        adj[a].push_back(pair<long long, long long>(b, 1));
        adj[b].push_back(pair<long long, long long>(a, 1));
      }
    }
    int ans = 0;
    ok = true;
    for (int i = 1; i < n + 1; i++) {
      if (colour[i] == -1) {
        colour[i] = 0;
        c[0] = c[1] = 0;
        dfs(i);
        ans += max(c[0], c[1]);
      }
    }
    if (!ok) {
      ans = -1;
    }
    cout << ans << "\n";
  }
}
