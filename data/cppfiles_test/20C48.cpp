#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
void query() {
  int n, m;
  cin >> n >> m;
  vector<string> t(n);
  for (auto& i : t) cin >> i;
  vector<vector<int>> col(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      col[i][j] = (i > 0 ? col[i - 1][j] : 0) + t[i][j] - '0';
  int res = inf;
  queue<pair<int, int>> q;
  for (int a = 5; a <= n; a++) {
    for (int i = 0; i <= n - a; i++) {
      while (!q.empty()) q.pop();
      pair<int, int> X(inf, 0);
      int add = 0;
      for (int j = 0; j < m; j++) {
        while (q.size() >= 3) {
          if (q.front().first - q.front().second < X.first - X.second)
            X = q.front();
          q.pop();
        }
        int A = col[i + a - 2][j] - col[i][j];
        if (j - 3 >= 0) res = min(res, X.first - X.second + add + a - 2 - A);
        if (j > 0)
          add += A + 2 - (int)(t[i][j] - '0') - (int)(t[i + a - 1][j] - '0');
        q.push({a - 2 - A, add});
      }
    }
  }
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int q = 1;
  cin >> q;
  while (q--) query();
  return 0;
}
