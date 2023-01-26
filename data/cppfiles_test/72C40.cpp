#include <bits/stdc++.h>
using namespace std;
int n = 1e9;
int l, r, u, d, cnt;
int ans11, ans1n, ansn1, ansnn;
int que(int x, int y) {
  assert(++cnt <= 40);
  printf("? %d %d\n", x, y);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}
int main() {
  int L = 1, R = n, mid = (R + L) >> 1;
  int ansl = que(L, 1), ansr = que(R, 1), ans = que(mid, 1), lastans;
  ans11 = ansl, ansn1 = ansr, ansnn = que(n, n);
  if (ansl == -1) l = 1, d = 1;
  if (ansr == -1) r = n, d = 1;
  if (ans == -1) d = 1;
  while (!d) {
    if (ansl - ans == mid - L)
      L = mid, ansl = ans;
    else if (ansr - ans == R - mid)
      R = mid, ansr = ans;
    else {
      d = ans + 1;
      break;
    }
    mid = (L + R) >> 1;
    lastans = ans;
    ans = que(mid, 1);
    if (lastans == ans) d = ans + 1;
    if (ans == -1) d = 1;
  }
  l = ans11 - d + 2;
  r = n + d - 1 - ansn1;
  u = 2 * n - r - ansnn;
  printf("! %d %d %d %d\n", l, d, r, u);
}
