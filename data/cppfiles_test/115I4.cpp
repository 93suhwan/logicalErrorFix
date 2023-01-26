#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long pw(long long a, long long t) {
  long long res = 1;
  while (t) {
    if (t & 1) res = res * a % mod;
    a = a * a % mod, t /= 2;
  }
  return res;
}
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  long long n, m, q;
  cin >> n >> m >> q;
  long long row[n][2], col[m][2];
  memset(row, 0, sizeof row);
  memset(col, 0, sizeof col);
  long long ar = n, ac = m, br = 0, bc = 0;
  map<pair<long long, long long>, long long> a;
  while (q--) {
    long long x, y, t;
    cin >> x >> y >> t;
    --x, --y;
    if (t == -1) {
      if (a.count({x, y})) {
        long long k = a[{x, y}];
        a.erase({x, y});
        {
          long long my = y % 2;
          if (!k) my ^= 1;
          row[x][my]--;
          if (row[x][my ^ 1] > 0 and row[x][my] == 0) br--;
          if (row[x][my ^ 1] == 0 and row[x][my] == 0) ar++;
        }
        {
          long long mx = x % 2;
          if (!k) mx ^= 1;
          col[y][mx]--;
          if (col[y][mx ^ 1] > 0 and col[y][mx] == 0) bc--;
          if (col[y][mx ^ 1] == 0 and col[y][mx] == 0) ac++;
        }
      }
    } else {
      if (a.count({x, y})) {
        long long k = a[{x, y}];
        a.erase({x, y});
        {
          long long my = y % 2;
          if (!k) my ^= 1;
          row[x][my]--;
          if (row[x][my ^ 1] > 0 and row[x][my] == 0) br--;
          if (row[x][my ^ 1] == 0 and row[x][my] == 0) ar++;
        }
        {
          long long mx = x % 2;
          if (!k) mx ^= 1;
          col[y][mx]--;
          if (col[y][mx ^ 1] > 0 and col[y][mx] == 0) bc--;
          if (col[y][mx ^ 1] == 0 and col[y][mx] == 0) ac++;
        }
      }
      {
        long long k = t;
        a[{x, y}] = k;
        {
          long long my = y % 2;
          if (!k) my ^= 1;
          row[x][my]++;
          if (row[x][my ^ 1] > 0 and row[x][my] == 1) br++;
          if (row[x][my ^ 1] == 0 and row[x][my] == 1) ar--;
        }
        {
          long long mx = x % 2;
          if (!k) mx ^= 1;
          col[y][mx]++;
          if (col[y][mx ^ 1] > 0 and col[y][mx] == 1) bc++;
          if (col[y][mx ^ 1] == 0 and col[y][mx] == 1) ac--;
        }
      }
    }
    long long res = 0;
    if (br == 0) res = (res + pw(2, ar)) % mod;
    if (bc == 0) res = (res + pw(2, ac)) % mod;
    if (br == 0 and bc == 0) res = (res + mod - 1) % mod;
    if (ar == n and ac == m) res = (res + mod - 1) % mod, assert(a.size() == 0);
    cout << res << '\n';
  }
}
