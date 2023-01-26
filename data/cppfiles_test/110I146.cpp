#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
template <typename T>
void readmain(T &x) {
  bool neg = false;
  unsigned char c = getchar();
  for (; (c ^ 48) > 9; c = getchar())
    if (c == '-') neg = true;
  for (x = 0; (c ^ 48) < 10; c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
  if (neg) x = -x;
}
template <typename T>
T &read(T &x) {
  readmain(x);
  return x;
}
template <typename T, typename... Tr>
void read(T &x, Tr &...r) {
  readmain(x);
  read(r...);
}
struct point {
  int x, y, c;
} p[4][N];
int n, x[N], y[N], c[N], v[N], t1[N], t2[N];
bool cmp0(const point &a, const point &b) { return a.x < b.x; }
bool cmp1(const point &a, const point &b) { return a.x > b.x; }
bool cmp2(const point &a, const point &b) { return a.y < b.y; }
bool cmp3(const point &a, const point &b) { return a.y > b.y; }
bool chk(int v, int fsb, int c0, int c1, int c2) {
  int k = 0, cnt = 0, maxv = 0;
  while (cnt < v) cnt += p[fsb][k++].c == c0;
  if (fsb < 2) {
    maxv = p[fsb][k - 1].x;
    while (k < n && p[fsb][k].x == maxv) ++k;
  } else {
    maxv = p[fsb][k - 1].y;
    while (k < n && p[fsb][k].y == maxv) ++k;
  }
  for (int i = 0, i_end = n; i < i_end; ++i) t2[i] = t1[i] = 0;
  if (fsb < 2) {
    for (int i = k, i_end = n; i < i_end; ++i)
      if (p[fsb][i].c == c1) ++t1[p[fsb][i].y];
    for (int i = k, i_end = n; i < i_end; ++i)
      if (p[fsb][i].c == c2) ++t2[p[fsb][i].y];
  } else {
    for (int i = k, i_end = n; i < i_end; ++i)
      if (p[fsb][i].c == c1) ++t1[p[fsb][i].y];
    for (int i = k, i_end = n; i < i_end; ++i)
      if (p[fsb][i].c == c2) ++t2[p[fsb][i].y];
  }
  for (int i = 0, i_end = n - 1; i < i_end; ++i) t1[i + 1] += t1[i];
  for (int i = n - 1; i; --i) t2[i - 1] += t2[i];
  for (int i = 0, i_end = n - 1; i < i_end; ++i)
    if (t1[i] >= v && t2[i] >= v) return true;
  return false;
}
bool check(int v) {
  if (chk(v, 0, 1, 2, 3)) return true;
  if (chk(v, 0, 1, 3, 2)) return true;
  if (chk(v, 0, 2, 1, 3)) return true;
  if (chk(v, 0, 2, 3, 1)) return true;
  if (chk(v, 0, 3, 1, 2)) return true;
  if (chk(v, 0, 3, 2, 1)) return true;
  if (chk(v, 1, 1, 2, 3)) return true;
  if (chk(v, 1, 1, 3, 2)) return true;
  if (chk(v, 1, 2, 1, 3)) return true;
  if (chk(v, 1, 2, 3, 1)) return true;
  if (chk(v, 1, 3, 1, 2)) return true;
  if (chk(v, 1, 3, 2, 1)) return true;
  if (chk(v, 2, 1, 2, 3)) return true;
  if (chk(v, 2, 1, 3, 2)) return true;
  if (chk(v, 2, 2, 1, 3)) return true;
  if (chk(v, 2, 2, 3, 1)) return true;
  if (chk(v, 2, 3, 1, 2)) return true;
  if (chk(v, 2, 3, 2, 1)) return true;
  if (chk(v, 3, 1, 2, 3)) return true;
  if (chk(v, 3, 1, 3, 2)) return true;
  if (chk(v, 3, 2, 1, 3)) return true;
  if (chk(v, 3, 2, 3, 1)) return true;
  if (chk(v, 3, 3, 1, 2)) return true;
  if (chk(v, 3, 3, 2, 1)) return true;
  return false;
}
int solve() {
  int l = 1, r = n / 3 + 1, mid;
  while (r - l > 1) {
    mid = (l + r) >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  return l;
}
int main() {
  read(n);
  for (int i = 0, i_end = n; i < i_end; ++i) read(x[i], y[i], c[i]);
  for (int i = 0, i_end = n; i < i_end; ++i) v[i] = x[i];
  sort(v, v + n);
  for (int i = 0, i_end = n; i < i_end; ++i)
    x[i] = lower_bound(v, v + n, x[i]) - v;
  for (int i = 0, i_end = n; i < i_end; ++i) v[i] = y[i];
  sort(v, v + n);
  for (int i = 0, i_end = n; i < i_end; ++i)
    y[i] = lower_bound(v, v + n, y[i]) - v;
  for (int i = 0, i_end = n; i < i_end; ++i)
    p[0][i].x = x[i], p[0][i].y = y[i], p[0][i].c = c[i];
  for (int i = 0, i_end = n; i < i_end; ++i)
    p[1][i] = p[2][i] = p[3][i] = p[0][i];
  sort(p[0], p[0] + n, cmp0);
  sort(p[1], p[1] + n, cmp1);
  sort(p[2], p[2] + n, cmp2);
  sort(p[3], p[3] + n, cmp3);
  printf("%d\n", solve() * 3);
  return 0;
}
