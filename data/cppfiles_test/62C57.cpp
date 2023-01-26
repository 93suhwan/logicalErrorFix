#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using db = double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
template <class T>
using V = vector<T>;
template <class T, size_t SZ>
using AR = array<T, SZ>;
template <class T>
using PR = pair<T, T>;
template <class T>
int lwb(V<T>& a, const T& b) {
  return int(lower_bound(begin(a), end(a), b) - begin(a));
}
int g[1001][1001], c[1001][1001][2][2], d[1001][1001][3];
;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, qc;
  cin >> n >> m >> qc;
  memset(g, 0, sizeof(g));
  memset(c, 0, sizeof(c));
  memset(d, 0, sizeof(d));
  vector<ll> ans;
  vector<array<int, 2>> q(qc);
  ll total = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      d[i][j][0] = 1;
      if (i == 1) {
        if (j > 1) {
          d[i][j][1] = 1;
        }
      } else {
        d[i][j][2] = d[i - 1][j][0] + d[i - 1][j][1];
        if (j > 1) {
          d[i][j][1] = d[i][j - 1][0] + d[i][j - 1][2];
        }
      }
      total += d[i][j][0] + d[i][j][1] + d[i][j][2];
    }
  }
  for (int i = (0); i < (qc); ++i) {
    int r, c;
    cin >> r >> c;
    if (g[r][c]) {
      g[r][c] = 0;
      int x = r, y = c;
      ll cntu = 0, cntd = 0;
      x = r, y = c;
      while (true) {
        x--;
        if (x < 1) break;
        if (g[x][y]) break;
        cntu++;
        y--;
        if (y < 1) break;
        if (g[x][y]) break;
        cntu++;
      }
      x = r, y = c;
      while (true) {
        y++;
        if (y > m) break;
        if (g[x][y]) break;
        cntd++;
        x++;
        if (x > n) break;
        if (g[x][y]) break;
        cntd++;
      }
      total += (1 + cntu) * (1 + cntd);
      cntu = cntd = 0;
      x = r, y = c;
      while (true) {
        y--;
        if (y < 1) break;
        if (g[x][y]) break;
        cntu++;
        x--;
        if (x < 1) break;
        if (g[x][y]) break;
        cntu++;
      }
      x = r, y = c;
      while (true) {
        x++;
        if (x > n) break;
        if (g[x][y]) break;
        cntd++;
        y++;
        if (y > m) break;
        if (g[x][y]) break;
        cntd++;
      }
      total += (1 + cntu) * (1 + cntd) - 1;
      ans.push_back(total);
    } else {
      g[r][c] = 1;
      int x = r, y = c;
      ll cntu = 0, cntd = 0;
      x = r, y = c;
      while (true) {
        x--;
        if (x < 1) break;
        if (g[x][y]) break;
        cntu++;
        y--;
        if (y < 1) break;
        if (g[x][y]) break;
        cntu++;
      }
      x = r, y = c;
      while (true) {
        y++;
        if (y > m) break;
        if (g[x][y]) break;
        cntd++;
        x++;
        if (x > n) break;
        if (g[x][y]) break;
        cntd++;
      }
      total -= (1 + cntu) * (1 + cntd);
      cntu = cntd = 0;
      x = r, y = c;
      while (true) {
        y--;
        if (y < 1) break;
        if (g[x][y]) break;
        cntu++;
        x--;
        if (x < 1) break;
        if (g[x][y]) break;
        cntu++;
      }
      x = r, y = c;
      while (true) {
        x++;
        if (x > n) break;
        if (g[x][y]) break;
        cntd++;
        y++;
        if (y > m) break;
        if (g[x][y]) break;
        cntd++;
      }
      total -= (1 + cntu) * (1 + cntd) - 1;
      ans.push_back(total);
    }
  }
  for (int i = (0); i < (qc); ++i) {
    cout << ans[i] << endl;
  }
}
