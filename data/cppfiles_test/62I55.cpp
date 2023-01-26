#include <bits/stdc++.h>
using namespace std;
long long a[1010][1010][2];
long long n, m, q;
long long col[1010][1010];
long long sum = 0;
long long cntCl = 0;
void build() {
  for (long long i = 1; i <= n; i++) {
    for (long long i1 = 1; i1 <= m; i1++) {
      long long right1 = m - i1, right2 = n - i;
      if (right1 <= right2) {
        a[i][i1][0] = right1 * 2;
      } else {
        a[i][i1][0] = 1 + right2 * 2;
      }
      long long bottom1 = m - i1, bottom2 = n - i;
      if (bottom1 < bottom2) {
        a[i][i1][1] = 1 + bottom1 * 2;
      } else {
        a[i][i1][1] = bottom2 * 2;
      }
      sum += (a[i][i1][0] + a[i][i1][1]);
    }
  }
}
long long calc_new(long long x, long long y, long long nxt) {
  if (x > n || y > m || col[x][y] == 1) {
    return 0;
  }
  return 1 + calc_new(x + (nxt == 1), y + (nxt == 0), 1 - nxt);
}
void rise_up(long long x, long long y, long long val, long long nxt) {
  if (x < 1 || y < 1 || col[x][y] == 1) {
    return;
  }
  sum += val;
  a[x][y][1 - nxt] += val;
  rise_up(x - (nxt == 1), y - (nxt == 0), val, 1 - nxt);
}
void printA() {
  cout << "------------------->\n";
  for (long long i = 1; i <= n; i++) {
    for (long long i1 = 1; i1 <= m; i1++) {
      cout << a[i][i1][1] << " ";
    }
    cout << endl;
  }
  cout << "<-------------------\n";
}
void solve() {
  cin >> n >> m >> q;
  build();
  cntCl = n * m;
  for (long long i = 1; i <= q; i++) {
    long long x, y;
    cin >> x >> y;
    {
      long long cnt_add = 0;
      if (col[x][y] == 0) {
        cnt_add = calc_new(x, y, 0);
        cout << cnt_add << endl;
        rise_up(x, y, -(cnt_add), 1);
        sum++;
        a[x][y][1]++;
      } else {
        col[x][y] = 0;
        cnt_add = calc_new(x, y, 0);
        rise_up(x, y, (cnt_add), 1);
        col[x][y] = 1;
        sum--;
        a[x][y][1]--;
      }
    }
    {
      long long cnt_add = 0;
      if (col[x][y] == 0) {
        cnt_add = calc_new(x, y, 1);
        rise_up(x, y, -(cnt_add), 0);
        sum++;
        a[x][y][0]++;
      } else {
        col[x][y] = 0;
        cnt_add = calc_new(x, y, 1);
        rise_up(x, y, (cnt_add), 0);
        col[x][y] = 1;
        sum--;
        a[x][y][0]--;
      }
    }
    cntCl += (col[x][y] == 1 ? 1 : -1);
    col[x][y] = 1 - col[x][y];
    cout << sum + cntCl << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long q = 1;
  for (long long i = 1; i <= q; i++) {
    solve();
  }
}
