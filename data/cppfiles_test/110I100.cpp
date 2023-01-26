#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e5 + 10, mod = 998244353;
int n, ans, p[3];
struct Node {
  int x, y, c;
} a[mxn], b[mxn];
int rd() {
  static int sl, fh, ch;
  sl = 0;
  fh = 1;
  ch = getchar();
  while (ch < '0' || '9' < ch) {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') sl = sl * 10 + ch - '0', ch = getchar();
  return sl * fh;
}
bool cmpx(const Node &A, const Node &B) {
  return A.x < B.x || (A.x == B.x && A.y < B.y);
}
bool cmpy(const Node &A, const Node &B) {
  return A.y < B.y || (A.y == B.y && A.x < B.x);
}
bool solve1(int num) {
  int i = 1, cnt = 0;
  for (; i <= n && cnt < num; ++i)
    if (a[i].c == p[0]) ++cnt;
  for (; i <= n; ++i)
    if (a[i].x != a[i - 1].x) break;
  cnt = 0;
  for (; i <= n && cnt < num; ++i)
    if (a[i].c == p[1]) ++cnt;
  if (cnt < num) return 0;
  for (; i <= n; ++i)
    if (a[i].x != a[i - 1].x) break;
  cnt = 0;
  for (; i <= n && cnt < num; ++i)
    if (a[i].c == p[2]) ++cnt;
  return cnt >= num;
}
bool solve2(int num) {
  int i = 1, cnt = 0;
  for (; i <= n && cnt < num; ++i)
    if (a[i].c == p[0]) ++cnt;
  for (; i <= n; ++i)
    if (a[i].x != a[i - 1].x) break;
  memcpy(b + i, a + i, (n - i + 2) * sizeof(Node));
  sort(b + i, b + n + 1, cmpy);
  cnt = 0;
  for (; i <= n && cnt < num; ++i)
    if (a[i].c == p[1]) ++cnt;
  if (cnt < num) return 0;
  for (; i <= n; ++i)
    if (a[i].y != a[i - 1].y) break;
  cnt = 0;
  for (; i <= n && cnt < num; ++i)
    if (a[i].c == p[2]) ++cnt;
  return cnt >= num;
}
bool check(int x) {
  for (int T = 0; T < 4; ++T) {
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    sort(a + 1, a + n + 1, cmpx);
    do {
      if (T < 2 && solve1(x)) return 1;
      if (solve2(x)) return 1;
    } while (next_permutation(p, p + 3));
    for (int i = 1; i <= n; ++i) swap(a[i].x, a[i].y), a[i].y = -a[i].y;
  }
  return 0;
}
int main() {
  n = rd();
  for (int i = 1; i <= n; ++i) a[i].x = rd(), a[i].y = rd(), a[i].c = rd();
  int l = 1, r = n / 3;
  while (l <= r) {
    if (check(((l + r) >> 1)))
      ans = ((l + r) >> 1), l = ((l + r) >> 1) + 1;
    else
      r = ((l + r) >> 1) - 1;
  }
  printf("%d\n", ans * 3);
  return 0;
}
