#include <bits/stdc++.h>
using namespace std;
void fileReading() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
const int mx = 2e5 + 5;
int n;
vector<int> adj[mx];
int sm, bud, tot;
void dfs(int i, int p) {
  int L = 0, T = 0;
  for (int x : adj[i])
    if (x != p) {
      dfs(x, i);
      T++;
      if (adj[x].size() == 1) L++, tot++;
    }
  if (i != 0 and L == T and adj[i].size() > 1) {
    sm += L;
    bud++;
  }
}
void solve() {
  cin >> n;
  sm = bud = tot = 0;
  for (int i = 0; i < n; i++) adj[i].clear();
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(0, 0);
  if (sm == tot)
    cout << tot - bud + 1 << endl;
  else
    cout << tot - bud << endl;
}
int main() {
  fileReading();
  int tc = 1;
  cin >> tc;
  while (tc--) solve();
}
