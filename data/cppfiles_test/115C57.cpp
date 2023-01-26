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
  array<int, 2> all = {0, 0};
  vector<array<int, 2>> rows(n + 1);
  vector<array<int, 2>> cols(m + 1);
  int bad_cols = 0;
  int bad_rows = 0;
  int free_cols = m;
  int free_rows = n;
  for (int i = 0; i < k; i++) {
    int x, y, v;
    cin >> x >> y >> v;
    if (rows[x][0] == 0 && rows[x][1] == 0) free_rows--;
    if (cols[y][0] == 0 && cols[y][1] == 0) free_cols--;
    if (rows[x][0] != 0 && rows[x][1] != 0) bad_rows--;
    if (cols[y][0] != 0 && cols[y][1] != 0) bad_cols--;
    auto it = vals.find({x, y});
    if (it != vals.end()) {
      rows[x][(y + it->second) % 2]--;
      cols[y][(x + it->second) % 2]--;
      all[(x + y + it->second) % 2]--;
      if (v < 0) vals.erase(it);
    }
    if (v >= 0) {
      rows[x][(y + v) % 2]++;
      cols[y][(x + v) % 2]++;
      all[(x + y + v) % 2]++;
      vals[{x, y}] = v;
    }
    if (rows[x][0] == 0 && rows[x][1] == 0) free_rows++;
    if (cols[y][0] == 0 && cols[y][1] == 0) free_cols++;
    if (rows[x][0] != 0 && rows[x][1] != 0) bad_rows++;
    if (cols[y][0] != 0 && cols[y][1] != 0) bad_cols++;
    long long resR = (bad_rows == 0) ? pw(2, free_rows) : 0;
    long long resC = (bad_cols == 0) ? pw(2, free_cols) : 0;
    int common = (int)(all[0] == 0) + (int)(all[1] == 0);
    long long res = (resR + resC + MOD - common) % MOD;
    cout << res << "\n";
  }
  return 0;
}
