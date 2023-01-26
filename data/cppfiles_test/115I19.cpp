#include <bits/stdc++.h>
using namespace std;
const int mo = 998244353;
const int _ = 1e6 + 5;
int n, m, Q;
int r[_][2][2], c[_][2][2], rz[_], cz[_];
int notr, notc;
int pw[_];
set<int> row, col;
map<pair<int, int>, bool> f;
int spj[2][2];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  pw[0] = 1;
  for (int i = 1; i <= 1e6; i++) pw[i] = 2ll * pw[i - 1] % mo;
  cin >> n >> m >> Q;
  while (Q--) {
    int x, y, o;
    cin >> x >> y >> o;
    if (o == -1) {
      if (f.count(make_pair(x, y))) {
        int k = f[make_pair(x, y)];
        spj[(x + y) & 1][k]--;
        f.erase(make_pair(x, y));
        r[x][y & 1][k]--;
        rz[x]--;
        if (r[x][y & 1][k] == 0 && (r[x][(y & 1) ^ 1][k] || r[x][y & 1][k ^ 1]))
          notr--;
        if (rz[x] == 0) row.erase(x);
        c[y][x & 1][k]--;
        cz[y]--;
        if (c[y][x & 1][k] == 0 && (c[y][(x & 1) ^ 1][k] || c[y][x & 1][k ^ 1]))
          notc--;
        if (cz[y] == 0) col.erase(y);
      }
    } else {
      if (!f.count(make_pair(x, y))) {
        f[make_pair(x, y)] = o;
        spj[(x + y) & 1][o]++;
        if (r[x][y & 1][o] == 0 && (r[x][(y & 1) ^ 1][o] || r[x][y & 1][o ^ 1]))
          notr++;
        if (rz[x] == 0) row.insert(x);
        r[x][y & 1][o]++;
        rz[x]++;
        if (c[y][x & 1][o] == 0 && (c[y][(x & 1) ^ 1][o] || c[y][x & 1][o ^ 1]))
          notc++;
        if (cz[y] == 0) col.insert(y);
        c[y][x & 1][o]++;
        cz[y]++;
      } else if (f[make_pair(x, y)] != o) {
        f[make_pair(x, y)] = o;
        spj[(x + y) & 1][o]++;
        spj[(x + y) & 1][o ^ 1]--;
        r[x][y & 1][o ^ 1]--;
        if (r[x][y & 1][o ^ 1] == 0 &&
            (r[x][(y & 1) ^ 1][o ^ 1] || r[x][y & 1][o]))
          notr--;
        if (r[x][y & 1][o] == 0 && (r[x][(y & 1) ^ 1][o] || r[x][y & 1][o ^ 1]))
          notr++;
        r[x][y & 1][o]++;
        c[y][x & 1][o ^ 1]--;
        if (c[y][x & 1][o ^ 1] == 0 &&
            (c[y][(x & 1) ^ 1][o ^ 1] || c[y][x & 1][o]))
          notc--;
        if (c[y][x & 1][o] == 0 && (c[y][(x & 1) ^ 1][o] || c[y][x & 1][o ^ 1]))
          notc++;
        c[y][x & 1][o]++;
      }
    }
    if (notr && notc) {
      cout << 0 << endl;
    } else if (notr) {
      cout << pw[m - (int)col.size()] << endl;
    } else if (notc) {
      cout << pw[n - (int)row.size()] << endl;
    } else {
      int ret = (pw[m - (int)col.size()] + pw[n - (int)row.size()]) % mo;
      if ((!spj[0][1]) && (!spj[1][0])) ret = (ret + mo - 1) % mo;
      if ((!spj[0][0]) && (!spj[1][1])) ret = (ret + mo - 1) % mo;
      cout << ret << endl;
    }
  }
  return 0;
}
