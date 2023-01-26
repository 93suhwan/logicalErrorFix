#include <bits/stdc++.h>
using namespace std;
void fileReading() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
const int mx = 2e5 + 5;
int n, tot, crit;
vector<int> adj[mx];
bool even[mx], odd[mx];
void dfs(int i, int p, int dep) {
  int sz = (!i) ? adj[i].size() : (int)adj[i].size() - 1, cnt = 0;
  for (int x : adj[i])
    if (x != p) {
      dfs(x, i, dep + 1);
      odd[i] &= odd[x];
      even[i] &= even[x];
      if (sz >= 2 and ((dep % 2 == 0 and even[x]) or (dep % 2 and odd[x]))) {
        crit++;
        cnt++;
      }
    }
  if (sz and cnt == sz) crit--;
  if (!sz) {
    tot++, odd[i] = dep % 2, even[i] = !odd[i];
  }
}
void solve() {
  cin >> n;
  tot = crit = 0;
  for (int i = 0; i < n; i++) adj[i].clear(), even[i] = odd[i] = 1;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(0, 0, 0);
  cout << tot - crit << endl;
}
int main() {
  fileReading();
  int tc = 1;
  cin >> tc;
  while (tc--) solve();
}
