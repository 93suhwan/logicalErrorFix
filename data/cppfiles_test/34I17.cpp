#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int vis[N];
vector<pair<int, int> > ost;
int t[N];
bool x[N];
vector<int> dod[N];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> t[i];
  for (int i = 1; i <= 10000; i++) vis[i] = -1;
  dod[0].push_back(0);
  x[0] = 1;
  ost.push_back({0, 0});
  vis[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = ost.size() - 1; j >= 0; j--) {
      if (ost[j].first <= vis[t[i]]) break;
      if (t[i] <= ost[j].second) continue;
      for (auto curr : dod[ost[j].first]) {
        if (!x[curr ^ t[i]]) {
          x[curr ^ t[i]] = 1;
          dod[i].push_back(curr ^ t[i]);
        }
      }
    }
    if (vis[t[i]] == -1) ost.push_back({i, t[i]});
    vis[t[i]] = i;
  }
  vector<int> ans;
  for (int i = 0; i <= 10000; i++)
    if (x[i]) ans.push_back(i);
  cout << ans.size() << "\n";
  for (auto i : ans) cout << i << " ";
  cout << "\n";
}
int main() { solve(); }
