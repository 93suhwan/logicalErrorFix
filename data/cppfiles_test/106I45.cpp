#include <bits/stdc++.h>
using namespace std;
const int C = 1e6;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(1 << n);
  vector<vector<int>> idA(C + 5);
  for (int i = 0; i < 1 << n; i++) {
    cin >> a[i];
    idA[a[i]].push_back(i);
  }
  vector<vector<pair<int, int>>> atCost(C * 2 + 5);
  vector<int> flag(1 << n);
  for (int cost = C; cost; cost--)
    for (int x : idA[cost])
      if (!flag[x]) {
        int bestY = -1;
        for (int i = 0; i < n; i++) {
          int y = x ^ 1 << i;
          if (!flag[y] && (bestY < 0 || a[y] > a[bestY])) bestY = y;
        }
        if (bestY >= 0) {
          flag[x] = flag[bestY] = 1;
          atCost[a[x] + a[bestY]].push_back({x, bestY});
        }
      }
  int ans = 0;
  vector<int> used(1 << n);
  for (int cost = C * 2; cost; cost--)
    for (auto [x, y] : atCost[cost]) {
      if (used[x] || used[y]) continue;
      ans += cost;
      used[x] = used[y] = 1;
      if (!--k) {
        cout << ans << endl;
        return 0;
      }
      int cx = -1, maxCx = -1;
      int cy = -1, maxCy = -1;
      for (int i = 0; i < n; i++) {
        int xx = x ^ 1 << i;
        if (!used[xx] && a[xx] > maxCx) {
          maxCx = a[xx];
          cx = xx;
        }
        int yy = y ^ 1 << i;
        if (!used[yy] && a[yy] > maxCy) {
          maxCy = a[yy];
          cy = yy;
        }
      }
      if (cx >= 0 && cy >= 0) atCost[a[cx] + a[cy]].push_back({cx, cy});
    }
  cout << ans << endl;
}
