#include <bits/stdc++.h>
using namespace std;
bool surround(vector<vector<char>> &g, pair<long long, long long> &x, char &c) {
  if (g[x.first - 1][x.second] == c) return false;
  if (g[x.first + 1][x.second] == c) return false;
  if (g[x.first][x.second - 1] == c) return false;
  if (g[x.first][x.second + 1] == c) return false;
  return true;
}
void print(vector<pair<long long, long long>> &x,
           vector<pair<long long, long long>> &y, vector<vector<char>> &g) {
  long long i, n = x.size();
  char c;
  for (i = 0; i < n; i++) {
    x[i].first++;
    x[i].second++;
    y[i].first++;
    y[i].second++;
    for (c = 'a';; c++) {
      if (surround(g, x[i], c) && surround(g, y[i], c)) break;
    }
    g[x[i].first][x[i].second] = c;
    g[y[i].first][y[i].second] = c;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, n, m, k, s, l, i, j, h;
  vector<pair<long long, long long>> x, y;
  cin >> t;
  while (t-- > 0) {
    cin >> n >> m >> k;
    x = vector<pair<long long, long long>>((n * m) / 2, {-1ll, -1ll});
    y = vector<pair<long long, long long>>((n * m) / 2, {-1ll, -1ll});
    j = 0;
    if (n % 2 == 1) {
      s = m / 2;
      for (i = 0; i < m; i += 2, j++) {
        x[j] = {n - 1, i};
        y[j] = {n - 1, i + 1};
      }
    } else {
      s = 0;
    }
    l = (n * m) / 2;
    if (m % 2 == 1) {
      l -= n / 2;
      for (i = 0; i < n; i += 2, j++) {
        x[j] = {i, m - 1};
        y[j] = {i + 1, m - 1};
      }
    }
    k -= s;
    if (k >= 0 && k % 2 == 0 && k <= l) {
      cout << "YES\n";
      for (i = 0; i + 1 < n; i += 2) {
        for (h = 0; h + 1 < m; h += 2) {
          if (k > 0) {
            x[j] = {i, h};
            y[j] = {i, h + 1};
            j++;
            x[j] = {i + 1, h};
            y[j] = {i + 1, h + 1};
            j++;
            k -= 2;
          } else {
            x[j] = {i, h};
            y[j] = {i + 1, h};
            j++;
            x[j] = {i, h + 1};
            y[j] = {i + 1, h + 1};
            j++;
          }
        }
      }
      vector<vector<char>> g(n + 2, vector<char>(m + 2, '\0'));
      print(x, y, g);
      for (i = 1; i <= n; i++) {
        for (h = 1; h <= m; h++) cout << g[i][h];
        cout << "\n";
      }
    } else
      cout << "NO\n";
  }
  return 0;
}
