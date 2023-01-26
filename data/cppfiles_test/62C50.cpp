#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m, q, a[N][N];
long long tot;
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      int x = n - i + 1, y = m - j + 1;
      int tt = min(x, y);
      tot += tt * 4 - 2;
      if (x == y) tot--;
    }
  while (q--) {
    int x, y;
    cin >> x >> y;
    int flag;
    if (a[x][y] == 1)
      flag = -1;
    else
      flag = 1;
    a[x][y] ^= 1;
    int last;
    long long num1 = 0, num2 = 0;
    int tx = x, ty = y;
    last = 1;
    while (tx >= 1 && ty >= 1) {
      num1++;
      if (last == 1)
        tx--;
      else
        ty--;
      if (a[tx][ty] == 1) break;
      last ^= 1;
    }
    last = 0;
    tx = x, ty = y;
    while (tx <= n && ty <= m) {
      num2++;
      if (last == 1)
        tx++;
      else
        ty++;
      if (a[tx][ty] == 1) break;
      last ^= 1;
    }
    tot -= num1 * num2 * flag;
    num1 = 0, num2 = 0;
    tx = x, ty = y;
    last = 0;
    while (tx >= 1 && ty >= 1) {
      num1++;
      if (last == 1)
        tx--;
      else
        ty--;
      if (a[tx][ty] == 1) break;
      last ^= 1;
    }
    last = 1;
    tx = x, ty = y;
    while (tx <= n && ty <= m) {
      num2++;
      if (last == 1)
        tx++;
      else
        ty++;
      if (a[tx][ty] == 1) break;
      last ^= 1;
    }
    tot -= num1 * num2 * flag;
    tot += flag;
    cout << tot << endl;
  }
  return 0;
}
