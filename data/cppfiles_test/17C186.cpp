#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int x = 0, sgn = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') sgn = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return sgn * x;
}
const int maxn = 50000 + 5;
int T, n, r[maxn][5];
bool cmp(int i, int j) {
  int cnt = 0;
  for (int k = 0; k < (5); ++k)
    if (r[i][k] < r[j][k] && ++cnt == 3) break;
  return cnt == 3;
}
int main() {
  T = read();
  while (T--) {
    n = read();
    for (int i = 0; i < (n); ++i)
      for (int j = 0; j < (5); ++j) {
        r[i][j] = read();
      }
    int winner = 0;
    for (int i = 0; i < (n); ++i)
      if (winner != i && !cmp(winner, i)) winner = i;
    bool ok = true;
    for (int i = 0; i < (n); ++i)
      if (winner != i && !cmp(winner, i)) {
        ok = false;
        break;
      }
    if (ok)
      cout << winner + 1 << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
