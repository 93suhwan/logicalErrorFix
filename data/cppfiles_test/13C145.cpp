#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<array<long long, 3>> pairs;
  if (n % 2 == 1) {
    k -= m / 2;
    for (long long i = 0; i < m; i += 2) {
      pairs.push_back({n - 1, i, 0});
    }
  }
  if (m % 2 == 1) {
    for (long long i = 0; i < n; i += 2) {
      pairs.push_back({i, m - 1, 1});
    }
  }
  long long new_size = (n - n % 2) * (m - m % 2) / 2;
  if (k % 2 == 0 && new_size >= k && new_size >= (new_size - k)) {
    cout << "YES"
         << "\n";
    for (long long i = 0; i < n - n % 2; i += 2) {
      for (long long j = 0; j < m - m % 2; j += 2) {
        if (k) {
          pairs.push_back({i, j, 0});
          pairs.push_back({i + 1, j, 0});
          k -= 2;
        } else {
          pairs.push_back({i, j, 1});
          pairs.push_back({i, j + 1, 1});
        }
      }
    }
    vector<vector<char>> mat(n, vector<char>(m, 0));
    for (auto [i, j, dir] : pairs) {
      set<char> taken;
      if (dir == 0) {
        for (auto [a, b] : vector<pair<long long, long long>>{{i - 1, j},
                                                              {i, j - 1},
                                                              {i + 1, j},
                                                              {i - 1, j + 1},
                                                              {i, j + 2},
                                                              {i + 1, j + 1}}) {
          if (0 <= a && a < n && 0 <= b && b < m) {
            taken.insert(mat[a][b]);
          }
        }
      } else {
        for (auto [a, b] : vector<pair<long long, long long>>{{i - 1, j},
                                                              {i, j - 1},
                                                              {i, j + 1},
                                                              {i + 1, j - 1},
                                                              {i + 2, j},
                                                              {i + 1, j + 1}}) {
          if (0 <= a && a < n && 0 <= b && b < m) {
            taken.insert(mat[a][b]);
          }
        }
      }
      for (char x = 'a'; x <= 'z'; x++) {
        if (!taken.count(x)) {
          mat[i][j] = x, mat[i + (dir == 1)][j + (dir == 0)] = x;
          break;
        }
      }
    }
    for (auto x : mat) {
      for (auto y : x) {
        cout << y;
      }
      cout << "\n";
    }
  } else {
    cout << "NO"
         << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  long long q;
  cin >> q;
  while (q--) solve();
  return 0;
}
