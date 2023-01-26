#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
const int MM = 998244353;
template <typename T, typename U>
static inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y) {
  if (x < y) x = y;
}
const int N = 105;
vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
int can[N][N][26];
int _runtimeTerror_() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<char>> ans(n, vector<char>(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      for (int k = 0; k < 26; ++k) can[i][j][k] = 0;
  auto assign = [&](int x, int y, int c) {
    ans[x][y] = char(c + 'a');
    for (int i = 0; i < 4; ++i) {
      int u = x + dx[i], v = y + dy[i];
      if (u >= 0 && u < n && v >= 0 && v < m) can[u][v][c] = 1;
    }
  };
  auto get = [&](vector<pair<pair<int, int>, pair<int, int>>> &a) {
    for (auto &[u, v] : a) {
      vector<int> cant(26, 0);
      auto [x, y] = u;
      auto [xx, yy] = v;
      for (int i = 0; i < 26; ++i) cant[i] = can[x][y][i] || can[xx][yy][i];
      for (int i = 0; i < 26; ++i) {
        if (cant[i] == 0) {
          assign(x, y, i);
          assign(xx, yy, i);
          break;
        }
      }
    }
  };
  vector<pair<pair<int, int>, pair<int, int>>> a;
  if (n % 2 == 0 && m % 2 == 0) {
    if (k % 2 == 0) {
      cout << "YES\n";
      for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < m; j += 2) {
          if (k == 0) {
            a.push_back({{i, j}, {i + 1, j}});
            a.push_back({{i, j + 1}, {i + 1, j + 1}});
          } else {
            k -= 2;
            a.push_back({{i, j}, {i, j + 1}});
            a.push_back({{i + 1, j}, {i + 1, j + 1}});
          }
        }
      }
    } else {
      cout << "NO\n";
      return 0;
    }
  } else if (n % 2 == 1 && m % 2 == 0) {
    k -= m / 2;
    if (k >= 0 && k % 2 == 0) {
      for (int j = 0; j < m; j += 2) {
        a.push_back({{n - 1, j}, {n - 1, j + 1}});
      }
      for (int i = 0; i < n - 1; i += 2) {
        for (int j = 0; j < m; j += 2) {
          if (k == 0) {
            a.push_back({{i, j}, {i + 1, j}});
            a.push_back({{i, j + 1}, {i + 1, j + 1}});
          } else {
            k -= 2;
            a.push_back({{i, j}, {i, j + 1}});
            a.push_back({{i + 1, j}, {i + 1, j + 1}});
          }
        }
      }
      cout << "YES\n";
    } else {
      cout << "NO\n";
      return 0;
    }
  } else if (n % 2 == 0 && m % 2 == 1) {
    if (k % 2 == 0 && k <= n * m / 2 - n / 2) {
      cout << "YES\n";
      for (int i = 0; i < n; i += 2) a.push_back({{i, m - 1}, {i + 1, m - 1}});
      for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < m - 1; j += 2) {
          if (k == 0) {
            a.push_back({{i, j}, {i + 1, j}});
            a.push_back({{i, j + 1}, {i + 1, j + 1}});
          } else {
            k -= 2;
            a.push_back({{i, j}, {i, j + 1}});
            a.push_back({{i + 1, j}, {i + 1, j + 1}});
          }
        }
      }
    } else {
      cout << "NO\n";
      return 0;
    }
  }
  get(a);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << ans[i][j];
    cout << "\n";
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  cin >> TESTS;
  while (TESTS--) _runtimeTerror_();
  return 0;
}
