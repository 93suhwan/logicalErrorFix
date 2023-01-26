#include <bits/stdc++.h>
using namespace std;
const int SIZE = 9000;
const int mod = 1e9 + 7;
const int maxv = 9000;
bool vis[maxv + 1][maxv + 1], in[maxv + 1][maxv + 1];
vector<int> v[maxv + 1];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= maxv; i++) v[i].push_back(0), in[i][0] = true;
  for (int i = 1; i <= n; i++) {
    for (auto it : v[a[i]]) {
      if (vis[a[i]][it]) continue;
      for (int j = a[i] + 1; j <= maxv; j++) {
        if (in[j][it ^ a[i]]) break;
        v[j].push_back(it ^ a[i]);
        in[j][it ^ a[i]] = true;
      }
      vis[a[i]][it] = true;
    }
    v[a[i]].clear();
  }
  set<int> ordered(v[maxv].begin(), v[maxv].end());
  cout << ordered.size() << '\n';
  for (auto it : ordered) cout << it << " ";
}
