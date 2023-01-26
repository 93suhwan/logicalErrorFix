#include <bits/stdc++.h>
using namespace std;
template <typename T>
void prt(const char* info, vector<T> v = vector<T>()) {
  if (0) {
    cout << info << " = ";
    for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
    cout << endl;
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    auto map = vector<vector<int>>(n, vector<int>(m, 0));
    auto getn = [&](int x, int y, int d) {
      if (x >= n || y >= m) return -1;
      auto ps = vector<int>();
      if (x - 1 >= 0) ps.push_back(map[x - 1][y]);
      if (y - 1 >= 0) ps.push_back(map[x][y - 1]);
      if (d == 0) {
        if (y + 1 >= m) return -1;
        if (x - 1 >= 0) ps.push_back(map[x - 1][y + 1]);
      }
      if (d == 1) {
        if (x + 1 >= n) return -1;
        if (y - 1 >= 0) ps.push_back(map[x + 1][y - 1]);
      }
      for (int i = 1;; i++) {
        bool ok = 1;
        for (auto e : ps) {
          if (e == i) ok = 0;
        }
        if (ok) return i;
      }
    };
    auto f = [&](int type) {
      map = vector<vector<int>>(n, vector<int>(m, 0));
      int ct = 0;
      bool over = 0;
      if (type == 0) {
        for (int j = 0; j < m; j += 2) {
          for (int i = 0; i < n; i++) {
            if (ct == k) {
              over = 1;
              break;
            }
            map[i][j] = getn(i, j, 0);
            map[i][j + 1] = getn(i, j, 0);
            ct += 1;
          }
          if (over) break;
        }
        if (k > ct) return false;
      } else {
        for (int i = 0; i < 1; i++) {
          for (int j = 0; j < m; j += 2) {
            if (ct == k) {
              over = 1;
              break;
            }
            map[i][j] = getn(i, j, 0);
            map[i][j + 1] = getn(i, j, 0);
            ct += 1;
          }
          if (over) break;
        }
        for (int j = 0; j < m; j += 2) {
          for (int i = 1; i < n; i++) {
            if (ct == k) {
              over = 1;
              break;
            }
            map[i][j] = getn(i, j, 0);
            map[i][j + 1] = getn(i, j, 0);
            ct += 1;
          }
          if (over) break;
        }
        if (k > ct) return false;
      }
      bool res = true;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (map[i][j] == 0) {
            map[i][j] = getn(i, j, 1);
            if (i + 1 < n) map[i + 1][j] = getn(i, j, 1);
          }
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (map[i][j] == -1) res = false;
        }
      }
      return res;
    };
    bool ans = false;
    if (f(0))
      ans = true;
    else if (f(1))
      ans = true;
    cout << (ans ? "YES" : "NO") << endl;
    if (ans) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cout << char('a' + map[i][j]);
        }
        cout << endl;
      }
    }
  }
}
