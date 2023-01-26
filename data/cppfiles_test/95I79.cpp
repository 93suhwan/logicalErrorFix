#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) cin >> a[i][j];
    int mxl[n][m], mxr[n][m], mnl[n][m], mnr[n][m];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (j == 0)
          mxl[i][j] = a[i][j], mnl[i][j] = a[i][j];
        else {
          mxl[i][j] = max(mxl[i][j - 1], a[i][j]);
          mnl[i][j] = min(mnl[i][j - 1], a[i][j]);
        }
      }
    for (int i = 0; i < n; i++)
      for (int j = m - 1; j >= 0; j--) {
        if (j == m - 1)
          mxr[i][j] = a[i][j], mnr[i][j] = a[i][j];
        else {
          mxr[i][j] = max(mxr[i][j + 1], a[i][j]);
          mnr[i][j] = min(mnr[i][j + 1], a[i][j]);
        }
      }
    bool flag = false;
    for (int k = 1; k < m && !flag; k++) {
      vector<pair<int, int>> blue_mx(n);
      set<pair<int, int>> blue_mn;
      for (int i = 0; i < n; i++) {
        blue_mx[i] = {mxl[i][k - 1], i};
        blue_mn.emplace(mnr[i][k], i);
      }
      sort(blue_mx.begin(), blue_mx.end());
      int red_mx = -1;
      while (!blue_mx.empty()) {
        int x = blue_mx.back().first;
        while (!blue_mx.empty() && blue_mx.back().first == x) {
          int i = blue_mx.back().second;
          blue_mx.pop_back();
          blue_mn.erase(make_pair(mnr[i][k], i));
          red_mx = max(red_mx, mxr[i][k]);
        }
        if (blue_mx.empty()) break;
        if (red_mx > 0 && red_mx < blue_mn.begin()->first) {
          cout << "YES\n";
          vector<bool> blue(n, false);
          for (auto& e : blue_mx) blue[e.second] = true;
          for (bool r : blue) cout << (r ? 'B' : 'R');
          cout << ' ' << k << '\n';
          flag = true;
          break;
        }
      }
    }
    if (!flag) cout << "No\n";
  }
}
