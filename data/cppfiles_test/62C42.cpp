#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> a(n, vector<int>(m, 1));
  vector<vector<int>> b(n, vector<int>(m));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      if (a[i][j]) {
        b[i][j] = max(b[i][j], i + j);
        if (i && j && a[i - 1][j - 1]) {
          b[i - 1][j - 1] = b[i][j];
        }
      }
    }
  }
  long long ans = n * m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!a[i][j]) {
        continue;
      }
      if (i) {
        if (a[i - 1][j]) {
          int A = (b[i][j] - i - j) / 2 + 1;
          int B = (b[i - 1][j] - i + 1 - j) / 2 + 1;
          if (A == B) {
            ans += A + B - 1;
          } else if (A < B) {
            ans += A * 2;
          } else {
            ans += B * 2 - 1;
          }
        }
      }
      if (j + 1 < m) {
        if (a[i][j + 1]) {
          int A = (b[i][j] - i - j) / 2 + 1;
          int B = (b[i][j + 1] - i - j - 1) / 2 + 1;
          if (A == B) {
            ans += A + B - 1;
          } else if (A > B) {
            ans += B * 2;
          } else {
            ans += A * 2 - 1;
          }
        }
      }
    }
  }
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    int oldx = x, oldy = y;
    int p = min(n - x - 1, m - y - 1);
    x += p;
    y += p;
    vector<pair<int, int>> tmp;
    while (x >= 0 && y >= 0) {
      if (x + 1 < n && y == m - 1) {
        tmp.push_back({x + 1, y});
      }
      if (y - 1 >= 0) {
        tmp.push_back({x, y - 1});
      }
      tmp.push_back({x, y});
      x--;
      y--;
    }
    for (auto j : tmp) {
      b[j.first][j.second] = 0;
    }
    for (auto j : tmp) {
      if (a[j.first][j.second]) {
        b[j.first][j.second] = max(b[j.first][j.second], j.first + j.second);
        if (j.first && j.second && a[j.first - 1][j.second - 1]) {
          b[j.first - 1][j.second - 1] = b[j.first][j.second];
        }
      }
    }
    for (auto j : tmp) {
      if (!a[j.first][j.second]) {
        continue;
      }
      if (j.first) {
        if (a[j.first - 1][j.second]) {
          int A = (b[j.first][j.second] - j.first - j.second) / 2 + 1;
          int B = (b[j.first - 1][j.second] - j.first + 1 - j.second) / 2 + 1;
          if (A == B) {
            ans -= A + B - 1;
          } else if (A < B) {
            ans -= A * 2;
          } else {
            ans -= B * 2 - 1;
          }
        }
      }
      if (j.second + 1 < m) {
        if (a[j.first][j.second + 1]) {
          int A = (b[j.first][j.second] - j.first - j.second) / 2 + 1;
          int B = (b[j.first][j.second + 1] - j.first - j.second - 1) / 2 + 1;
          if (A == B) {
            ans -= A + B - 1;
          } else if (A > B) {
            ans -= B * 2;
          } else {
            ans -= A * 2 - 1;
          }
        }
      }
    }
    if (a[oldx][oldy] == 1) {
      ans--;
    } else {
      ans++;
    }
    a[oldx][oldy] ^= 1;
    for (auto j : tmp) {
      b[j.first][j.second] = 0;
    }
    for (auto j : tmp) {
      if (a[j.first][j.second]) {
        b[j.first][j.second] = max(b[j.first][j.second], j.first + j.second);
        if (j.first && j.second && a[j.first - 1][j.second - 1]) {
          b[j.first - 1][j.second - 1] = b[j.first][j.second];
        }
      }
    }
    for (auto j : tmp) {
      if (!a[j.first][j.second]) {
        continue;
      }
      if (j.first) {
        if (a[j.first - 1][j.second]) {
          int A = (b[j.first][j.second] - j.first - j.second) / 2 + 1;
          int B = (b[j.first - 1][j.second] - j.first + 1 - j.second) / 2 + 1;
          if (A == B) {
            ans += A + B - 1;
          } else if (A < B) {
            ans += A * 2;
          } else {
            ans += B * 2 - 1;
          }
        }
      }
      if (j.second + 1 < m) {
        if (a[j.first][j.second + 1]) {
          int A = (b[j.first][j.second] - j.first - j.second) / 2 + 1;
          int B = (b[j.first][j.second + 1] - j.first - j.second - 1) / 2 + 1;
          if (A == B) {
            ans += A + B - 1;
          } else if (A > B) {
            ans += B * 2;
          } else {
            ans += A * 2 - 1;
          }
        }
      }
    }
    cout << ans << endl;
  }
}
