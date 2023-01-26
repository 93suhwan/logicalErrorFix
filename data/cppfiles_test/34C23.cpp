#include <bits/stdc++.h>
using namespace std;
const int MAX = 8192;
vector<int> upd[MAX];
vector<int> least(MAX, MAX);
vector<bool> ok(MAX, false);
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int z = 0; z < MAX; z++) {
    upd[z].push_back(0);
  }
  least[0] = 0;
  ok[0] = true;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    for (int x : upd[v[i]]) {
      int p = x ^ v[i];
      ok[p] = true;
      for (int z = v[i] + 1; z < least[p]; z++) upd[z].push_back(p);
      least[p] = min(v[i], least[p]);
    }
    upd[v[i]].clear();
  }
  {
    int cnt = 0;
    for (int z = 0; z < MAX; z++) cnt += ok[z];
    cout << cnt << '\n';
    for (int z = 0; z < MAX; z++) {
      if (ok[z]) cout << z << ' ';
    }
    cout << '\n';
  }
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
