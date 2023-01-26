#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, val;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<vector<int>> g(8192, vector<int>(1, 0));
  vector<int> r(8192, 8191);
  vector<bool> b(8192);
  b[0] = true;
  for (int i = 0; i < n; i++) {
    cin >> val;
    for (auto cur : g[val]) {
      int nxt = cur ^ val;
      b[nxt] = true;
      while (r[nxt] > val) {
        g[r[nxt]].push_back(nxt);
        r[nxt]--;
      }
    }
    g[val].clear();
  }
  vector<int> v;
  for (int x = 0; x < 8192; x++)
    if (b[x]) v.push_back(x);
  cout << v.size() << endl;
  for (auto val : v) cout << val << " ";
  cout << endl;
  return 0;
}
