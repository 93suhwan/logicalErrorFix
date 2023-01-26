#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
long long pw(long long v, long long p) {
  long long res = 1;
  while (p != 0) {
    if ((p & 1) != 0) res = (res * v) % MOD;
    v = (v * v) % MOD;
    p >>= 1;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  map<pair<int, int>, int> vals;
  vector<array<int, 2>> rows(n + 1);
  vector<array<int, 2>> cols(m + 1);
  int bad_cols = 0;
  int bad_rows = 0;
  int free_cols = m;
  int free_rows = n;
  for (int i = 0; i < k; i++) {
    int x, y, v;
    cin >> x >> y >> v;
    bool was_free_row = rows[x][0] == 0 && rows[x][1] == 0;
    bool was_free_col = cols[y][0] == 0 && cols[y][1] == 0;
    bool was_bad_row = rows[x][0] != 0 && rows[x][1] != 0;
    bool was_bad_col = cols[y][0] != 0 && cols[y][1] != 0;
    auto it = vals.find({x, y});
    if (it != vals.end()) {
      rows[x][(y + it->second) % 2]--;
      cols[y][(x + it->second) % 2]--;
      if (v < 0) vals.erase(it);
    }
    if (v >= 0) {
      rows[x][(y + v) % 2]++;
      cols[y][(x + v) % 2]++;
      vals[{x, y}] = v;
    }
    bool is_free_row = rows[x][0] == 0 && rows[x][1] == 0;
    bool is_free_col = cols[y][0] == 0 && cols[y][1] == 0;
    bool is_bad_row = rows[x][0] != 0 && rows[x][1] != 0;
    bool is_bad_col = cols[y][0] != 0 && cols[y][1] != 0;
    if (was_free_row) free_rows--;
    if (is_free_row) free_rows++;
    if (was_free_col) free_cols--;
    if (is_free_col) free_cols++;
    if (was_bad_row) bad_rows--;
    if (is_bad_row) bad_rows++;
    if (was_bad_col) bad_cols--;
    if (is_bad_col) bad_cols++;
    long long res;
    if (bad_rows > 0) {
      if (bad_cols > 0)
        res = 0;
      else
        res = pw(2, free_cols);
    } else {
      if (bad_cols > 0)
        res = pw(2, free_rows);
      else {
        res = (pw(2, free_cols) + pw(2, free_rows)) % MOD - 1;
        if (free_cols == m && free_rows == n) res--;
      }
    }
    cout << res << "\n";
  }
  return 0;
}
