#include <bits/stdc++.h>
using namespace std;
void test_case() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> v;
  for (int i = 0; i < n * m; i++) {
    int x;
    cin >> x;
    v.push_back(make_pair(x, i));
  }
  sort(v.begin(), v.end());
  vector<vector<pair<int, int>>> grid(n, vector<pair<int, int>>(m));
  int id = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) grid[i][j] = v[id++];
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < j; k++) {
        if (grid[i][j].first > grid[i][k].first and
            grid[i][j].second > grid[i][k].second)
          res++;
      }
    }
  }
  cout << res << endl;
}
int main() {
  int t = 1, cs = 0;
  cin >> t;
  while (t--) {
    test_case();
  }
  return 0;
}
