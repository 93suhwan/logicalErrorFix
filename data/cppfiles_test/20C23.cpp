#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int TESTS;
  cin >> TESTS;
  for (int TEST = 0; TEST < TESTS; ++TEST) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g, ps;
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      g.push_back(vector<int>());
      ps.push_back(vector<int>(1, 0));
      for (char c : s) {
        g.back().push_back(c - '0');
        ps.back().push_back(ps.back().back() + g.back().back());
      }
    }
    int best = n * m + 13;
    for (int l = 0; l < m; ++l) {
      for (int r = l + 3; r < m; ++r) {
        int minsum = ((r - l - 1) - (ps[0][r] - ps[0][l + 1])) -
                     (ps[0][r] - ps[0][l + 1] + (g[0][l] ^ 1) + (g[0][r] ^ 1));
        int lastsum = minsum;
        int currsum = ((r - l - 1) - (ps[4][r] - ps[4][l + 1]));
        for (int d = 0; d < 4; ++d) {
          currsum += (ps[d][r] - ps[d][l + 1] + (g[d][l] ^ 1) + (g[d][r] ^ 1));
        }
        best = min(best, currsum + minsum);
        for (int d = 5; d < n; ++d) {
          int u = d - 4;
          lastsum -= ((r - l - 1) - (ps[u - 1][r] - ps[u - 1][l + 1]));
          lastsum += ((r - l - 1) - (ps[u][r] - ps[u][l + 1]));
          lastsum -= (ps[u][r] - ps[u][l + 1] + (g[u][l] ^ 1) + (g[u][r] ^ 1));
          currsum -= ((r - l - 1) - (ps[d - 1][r] - ps[d - 1][l + 1]));
          currsum += ((r - l - 1) - (ps[d][r] - ps[d][l + 1]));
          currsum += (ps[d - 1][r] - ps[d - 1][l + 1] + (g[d - 1][l] ^ 1) +
                      (g[d - 1][r] ^ 1));
          minsum = min(minsum, lastsum);
          best = min(best, currsum + minsum);
        }
      }
    }
    cout << best << "\n";
  }
}
