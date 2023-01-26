#include <bits/stdc++.h>
using namespace std;
const int N = 2000006;
int n;
vector<int> adj[N];
bool rm[N], lf[N];
int totlf = 0;
int hlp = 0;
void dfs(int x, int p) {
  if ((int)adj[x].size() == 1 && x != 1) {
    lf[x] = true;
    totlf++;
    return;
  }
  for (int y : adj[x]) {
    if (y == p) continue;
    dfs(y, x);
  }
  rm[x] = true;
  for (int y : adj[x]) {
    if (y == p) continue;
    if (!lf[y] && !rm[y]) {
      rm[x] = false;
      break;
    }
  }
  lf[x] = true;
  int cnt = 0;
  for (int y : adj[x]) {
    if (y == p) continue;
    if (!rm[y]) {
      lf[x] = false;
    } else {
      cnt++;
    }
  }
  hlp += cnt - lf[x];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i < n; i++) {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    dfs(1, 1);
    totlf -= hlp;
    cout << totlf << endl;
    if (t) {
      totlf = 0;
      hlp = 0;
      for (int i = 1; i <= n; i++) {
        adj[i].clear();
        rm[i] = false;
        lf[i] = false;
      }
    }
  }
  return 0;
}
