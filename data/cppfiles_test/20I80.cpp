#include <bits/stdc++.h>
using namespace std;
inline int get_sum(vector<vector<int>> &precalc, int x1, int y1, int x2,
                   int y2) {
  return precalc[x2][y2] - precalc[x1 - 1][y2] - precalc[x2][y1 - 1] +
         precalc[x1 - 1][y1 - 1];
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> rectangle(m + 1, vector<bool>(n + 1));
  vector<vector<int>> prefix_sums(m + 1, vector<int>(n + 1));
  for (int y = 1; y <= n; y++) {
    string row;
    cin >> row;
    for (int x = 1; x <= m; x++) {
      rectangle[x][y] = (row[x - 1] - '0');
      prefix_sums[x][y] = prefix_sums[x - 1][y] + prefix_sums[x][y - 1] -
                          prefix_sums[x - 1][y - 1] + rectangle[x][y];
    }
  }
  int min_cost = 16;
  for (int x1 = 1; x1 <= m - 3; x1++)
    for (int y1 = 1; y1 <= n - 4; y1++)
      for (int y2 = y1 + 4; y2 <= n; y2++) {
        int common_part = get_sum(prefix_sums, x1 + 1, y1 + 1, x1 + 1, y2 - 1) +
                          (y2 - y1 - 1) -
                          get_sum(prefix_sums, x1, y1 + 1, x1, y2 - 1);
        for (int x2 = x1 + 3; x2 <= m; x2++) {
          common_part += get_sum(prefix_sums, x2 - 1, y1 + 1, x2 - 1, y2 - 1);
          common_part += 2 - rectangle[x2 - 2][y1] - rectangle[x1 + 1][y2];
          if (common_part >= min_cost) break;
          int curr_cost = common_part + (y2 - y1 - 1) -
                          get_sum(prefix_sums, x2, y1 + 1, x2, y2 - 1) + 2 -
                          rectangle[x2 - 1][y1] - rectangle[x2 - 1][y2];
          min_cost = min(curr_cost, min_cost);
        }
      }
  cout << min_cost << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int num_t;
  cin >> num_t;
  for (int test_c = 0; test_c < num_t; test_c++) {
    if (test_c == 11) {
      int n, m;
      cin >> n >> m;
      for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        cout << x << "\n";
      }
    }
    solve();
  }
  cout << endl;
  return 0;
}
