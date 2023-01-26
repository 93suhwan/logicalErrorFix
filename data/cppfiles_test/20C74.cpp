#include <bits/stdc++.h>
using namespace std;
int rectangleCost(int x, int y, int a, int b, vector<vector<int>> &sum) {
  return sum[a][b] - sum[a][y - 1] - sum[x - 1][b] + sum[x - 1][y - 1];
}
int invRectangle(int x, int y, int a, int b, vector<vector<int>> &sum) {
  return (a - x + 1) * (b - y + 1) - rectangleCost(x, y, a, b, sum);
}
int portalCost(int x, int y, int a, int b, vector<vector<int>> &sum) {
  int cost = 0;
  cost += rectangleCost(x + 1, y + 1, a - 1, b - 1, sum);
  cost += invRectangle(x + 1, y, a - 1, y, sum);
  cost += invRectangle(x + 1, b, a - 1, b, sum);
  cost += invRectangle(x, y + 1, x, b - 1, sum);
  cost += invRectangle(a, y + 1, a, b - 1, sum);
  return cost;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> tab(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (v[i - 1][j - 1] == '1') {
          tab[i][j] = 1;
        }
        sum[i][j] =
            sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + tab[i][j];
      }
    }
    int result = 1e9;
    for (int h = 5; h <= n; h++) {
      for (int i = h; i <= n; i++) {
        int cost = portalCost(i - h + 1, 1, i, 4, sum);
        result = min(result, cost);
        for (int j = 5; j <= m; j++) {
          cost = min(cost + rectangleCost(i - h + 2, j - 1, i - 1, j - 1, sum) -
                         invRectangle(i - h + 2, j - 1, i - 1, j - 1, sum) +
                         invRectangle(i - h + 2, j, i - 1, j, sum) + 2 -
                         tab[i - h + 1][j - 1] - tab[i][j - 1],
                     portalCost(i - h + 1, j - 3, i, j, sum));
          result = min(result, cost);
        }
      }
    }
    cout << result << "\n";
  }
  return 0;
}
