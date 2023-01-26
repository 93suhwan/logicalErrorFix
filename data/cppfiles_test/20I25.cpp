#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<string> temp = {"0110", "1001", "1001", "1001", "0110"};
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    int res = 20;
    for (int i = 0; i + 5 - 1 < n; i++)
      for (int j = 0; j + 4 - 1 < m; j++) {
        int cur = 0;
        for (int x = 0; x < 5; x++)
          for (int y = 0; y < 4; y++)
            if ((1 <= x && x <= 3) || (1 <= y && y <= 2)) {
              cur += (g[i + x][j + y] != temp[x][y]);
            }
        res = min(res, cur);
      }
    cout << res << '\n';
  }
  return 0;
}
