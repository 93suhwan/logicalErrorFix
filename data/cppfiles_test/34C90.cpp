#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 10;
bool vis[N][1 << 13];
int t[1000 * 1000 + 10];
vector<int> l[N];
bool res[1 << 13];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> t[i];
  for (int i = 1; i <= 5000; i++) l[i].push_back(0), vis[i][0] = 1;
  res[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < l[t[i]].size(); j++) {
      for (int k = t[i] + 1; k <= 5000; k++) {
        if (vis[k][l[t[i]][j] ^ t[i]]) break;
        vis[k][l[t[i]][j] ^ t[i]] = 1;
        l[k].push_back(l[t[i]][j] ^ t[i]);
      }
      res[l[t[i]][j] ^ t[i]] = 1;
    }
    l[t[i]].clear();
  }
  vector<int> ans;
  for (int i = 0; i < (1 << 13); i++)
    if (res[i]) ans.push_back(i);
  cout << ans.size() << "\n";
  for (auto i : ans) cout << i << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
}
