#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200 * 1000 + 1;
int ans[MAX_N];
map<int, vector<int>> maps;
void solve() {
  int n, k;
  cin >> n >> k;
  memset(ans, 0, n * sizeof(ans[0]));
  maps.clear();
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (maps[a].size() < k) {
      maps[a].push_back(i);
    }
  }
  int l = 0;
  for (auto &x : maps) {
    l += x.second.size();
  }
  l = l - (l % k);
  int cc = 0;
  int painted = 0;
  for (auto &x : maps) {
    for (auto &y : x.second) {
      ans[y] = ++cc;
      painted++;
      if (painted >= l) break;
      cc %= k;
    }
    if (painted >= l) break;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    solve();
  }
  return 0;
}
