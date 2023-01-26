#include <bits/stdc++.h>
using namespace std;
void read(int& x) {
  static char c;
  int f = 0;
  while (!isdigit(c = getchar()))
    if (c == '-') f = 1;
  x = c ^ 48;
  while (isdigit(c = getchar())) x = (x * 10) + (c ^ 48);
  if (f) x = -x;
}
void read(long long& x) {
  static char c;
  int f = 0;
  while (!isdigit(c = getchar()))
    if (c == '-') f = 1;
  x = c ^ 48;
  while (isdigit(c = getchar())) x = (x * 10) + (c ^ 48);
  if (f) x = -x;
}
void read(unsigned int& x) {
  static char c;
  while (!isdigit(c = getchar()))
    ;
  x = c ^ 48;
  while (isdigit(c = getchar())) x = (x * 10) + (c ^ 48);
}
void read(unsigned long long& x) {
  static char c;
  while (!isdigit(c = getchar()))
    ;
  x = c ^ 48;
  while (isdigit(c = getchar())) x = (x * 10) + (c ^ 48);
}
void chkmax(int& x, int y) {
  if (y > x) x = y;
}
void chkmin(int& x, int y) {
  if (y < x) x = y;
}
void chkmax(long long& x, long long y) {
  if (y > x) x = y;
}
void chkmin(long long& x, long long y) {
  if (y < x) x = y;
}
void chkmax(unsigned int& x, unsigned int y) {
  if (y > x) x = y;
}
void chkmin(unsigned int& x, unsigned int y) {
  if (y < x) x = y;
}
void chkmax(unsigned long long& x, unsigned long long y) {
  if (y > x) x = y;
}
void chkmin(unsigned long long& x, unsigned long long y) {
  if (y < x) x = y;
}
const int N = 2e5 + 10;
int n, m;
int X[N], Y[N], col[N];
int srt[N * 2];
int xPre[4][N], yPre[4][N];
int p[4];
bool case1(int mid) {
  int pos1, pos2;
  for (pos1 = 1; pos1 <= m; ++pos1)
    if (xPre[p[1]][pos1] >= mid) break;
  if (pos1 > m) return false;
  for (pos2 = pos1 + 1; pos2 <= m; ++pos2)
    if (xPre[p[2]][pos2] - xPre[p[2]][pos1 - 1] >= mid) break;
  if (pos2 > m) return false;
  return xPre[p[3]][m] - xPre[p[3]][pos2 - 1] >= mid;
}
bool case2(int mid) {
  int pos1, pos2;
  for (pos1 = 1; pos1 <= m; ++pos1)
    if (yPre[p[1]][pos1] >= mid) break;
  if (pos1 > m) return false;
  for (pos2 = pos1 + 1; pos2 <= m; ++pos2)
    if (yPre[p[2]][pos2] - yPre[p[2]][pos1 - 1] >= mid) break;
  if (pos2 > m) return false;
  return yPre[p[3]][m] - yPre[p[3]][pos2 - 1] >= mid;
}
int Buc[4][N];
bool case3(int mid) {
  int pos1, pos2;
  for (pos1 = 1; pos1 <= m; ++pos1)
    if (xPre[p[1]][pos1] >= mid) break;
  if (pos1 > m) return false;
  memset(Buc, 0, sizeof Buc);
  for (int i = 1; i <= n; ++i)
    if (X[i] >= pos1) ++Buc[col[i]][Y[i]];
  for (int c : {1, 2, 3})
    for (int i = 1; i <= m; ++i) Buc[c][i] += Buc[c][i - 1];
  for (pos2 = 1; pos2 <= m; ++pos2)
    if (Buc[p[2]][pos2] >= mid) break;
  if (pos2 > m) return false;
  return Buc[p[3]][m] - Buc[p[3]][pos2 - 1] >= mid;
}
bool case5(int mid) {
  int pos1, pos2;
  for (pos1 = m; pos1; --pos1)
    if (xPre[p[1]][m] - xPre[p[1]][pos1 - 1] >= mid) break;
  if (!pos1) return false;
  memset(Buc, 0, sizeof Buc);
  for (int i = 1; i <= n; ++i)
    if (X[i] <= pos1) ++Buc[col[i]][Y[i]];
  for (int c : {1, 2, 3})
    for (int i = 1; i <= m; ++i) Buc[c][i] += Buc[c][i - 1];
  for (pos2 = 1; pos2 <= m; ++pos2)
    if (Buc[p[2]][pos2] >= mid) break;
  if (pos2 > m) return false;
  return Buc[p[3]][m] - Buc[p[3]][pos2 - 1] >= mid;
}
bool case4(int mid) {
  int pos1, pos2;
  for (pos1 = 1; pos1 <= m; ++pos1)
    if (yPre[p[1]][pos1] >= mid) break;
  if (pos1 > m) return false;
  memset(Buc, 0, sizeof Buc);
  for (int i = 1; i <= n; ++i)
    if (Y[i] >= pos1) ++Buc[col[i]][X[i]];
  for (int c : {1, 2, 3})
    for (int i = 1; i <= m; ++i) Buc[c][i] += Buc[c][i - 1];
  for (pos2 = 1; pos2 <= m; ++pos2)
    if (Buc[p[2]][pos2] >= mid) break;
  if (pos2 > m) return false;
  return Buc[p[3]][m] - Buc[p[3]][pos2 - 1] >= mid;
}
bool case6(int mid) {
  int pos1, pos2;
  for (pos1 = m; pos1; --pos1)
    if (yPre[p[1]][m] - yPre[p[1]][pos1 - 1] >= mid) break;
  if (!pos1) return false;
  memset(Buc, 0, sizeof Buc);
  for (int i = 1; i <= n; ++i)
    if (Y[i] <= pos1) ++Buc[col[i]][X[i]];
  for (int c : {1, 2, 3})
    for (int i = 1; i <= m; ++i) Buc[c][i] += Buc[c][i - 1];
  for (pos2 = 1; pos2 <= m; ++pos2)
    if (Buc[p[2]][pos2] >= mid) break;
  if (pos2 > m) return false;
  return Buc[p[3]][m] - Buc[p[3]][pos2 - 1] >= mid;
}
bool check(int mid) {
  p[1] = 1, p[2] = 2, p[3] = 3;
  do {
    if (case1(mid)) return true;
    if (case2(mid)) return true;
    if (case3(mid)) return true;
    if (case5(mid)) return true;
    if (case4(mid)) return true;
    if (case6(mid)) return true;
  } while (next_permutation(p + 1, p + 4));
  return false;
}
void Work() {
  read(n);
  for (int i = 1; i <= n; ++i)
    read(X[i]), read(Y[i]), read(col[i]), srt[2 * i - 1] = X[i],
                                                      srt[2 * i] = Y[i];
  sort(srt + 1, srt + 2 * n + 1),
      m = unique(srt + 1, srt + 2 * n + 1) - srt - 1;
  for (int i = 1; i <= n; ++i)
    X[i] = lower_bound(srt + 1, srt + m + 1, X[i]) - srt,
    Y[i] = lower_bound(srt + 1, srt + m + 1, Y[i]) - srt;
  for (int i = 1; i <= n; ++i) ++xPre[col[i]][X[i]], ++yPre[col[i]][Y[i]];
  for (int c : {1, 2, 3})
    for (int i = 1; i <= m; ++i)
      xPre[c][i] += xPre[c][i - 1], yPre[c][i] += yPre[c][i - 1];
  int l = 1, r = n / 3, mid, ans = 1;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (check(mid))
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  printf("%d\n", 3 * ans);
}
int main() { Work(); }
