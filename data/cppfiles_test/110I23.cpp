#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, id, o;
} a[300010], b[300010];
bool cmpx(const node A, const node B) { return A.x < B.x; }
bool cmpy(const node A, const node B) { return A.y < B.y; }
int P[4], n;
int chk1(int x) {
  int r = 0, i = 1, lim;
  for (; i <= n && r < x; i++)
    if (a[i].id == P[1]) {
      r++, lim = a[i].x;
    }
  if (r < x) return 0;
  r = 0;
  for (; i <= n && r < x; i++)
    if (a[i].x > lim && a[i].id == P[2]) {
      r++, lim = a[i].x;
    }
  if (r < x) return 0;
  r = 0;
  for (; i <= n && r < x; i++)
    if (a[i].x > lim && a[i].id == P[3]) {
      r++, lim = a[i].x;
    }
  if (r < x) return 0;
  return 1;
}
int prt1(int x) {
  int r = 0, i = 1, lim;
  for (; i <= n && r < x; i++)
    if (a[i].id == P[1]) {
      printf("%d ", a[i].o);
      r++, lim = a[i].x;
    }
  r = 0;
  for (; i <= n && r < x; i++)
    if (a[i].x > lim && a[i].id == P[2]) {
      printf("%d ", a[i].o);
      r++, lim = a[i].x;
    }
  r = 0;
  for (; i <= n && r < x; i++)
    if (a[i].x > lim && a[i].id == P[3]) {
      printf("%d ", a[i].o);
      r++, lim = a[i].x;
    }
}
int chk4(int x) {
  int r = 0, i = 1, lim;
  for (; i <= n && r < x; i++)
    if (b[i].id == P[1]) {
      r++, lim = b[i].y;
    }
  if (r < x) return 0;
  r = 0;
  for (; i <= n && r < x; i++)
    if (b[i].y > lim && b[i].id == P[2]) {
      r++, lim = b[i].y;
    }
  if (r < x) return 0;
  r = 0;
  for (; i <= n && r < x; i++)
    if (b[i].y > lim && b[i].id == P[3]) {
      r++, lim = b[i].y;
    }
  if (r < x) return 0;
  return 1;
}
int prt4(int x) {
  int r = 0, i = 1, lim;
  for (; i <= n && r < x; i++)
    if (b[i].id == P[1]) {
      printf("%d ", b[i].o);
      r++, lim = b[i].y;
    }
  r = 0;
  for (; i <= n && r < x; i++)
    if (b[i].y > lim && b[i].id == P[2]) {
      printf("%d ", b[i].o);
      r++, lim = b[i].y;
    }
  r = 0;
  for (; i <= n && r < x; i++)
    if (b[i].y > lim && b[i].id == P[3]) {
      printf("%d ", b[i].o);
      r++, lim = b[i].y;
    }
}
int chk2(int x) {
  int r = 0, i = 1, lim, lim2;
  for (; i <= n && r < x; i++)
    if (a[i].id == P[1]) {
      r++, lim = a[i].x;
    }
  if (r < x) return 0;
  r = 0;
  for (i = 1; i <= n && r < x; i++)
    if (b[i].x > lim && b[i].id == P[2]) {
      r++, lim2 = b[i].y;
    }
  if (r < x) return 0;
  r = 0;
  for (; i <= n && r < x; i++)
    if (b[i].x > lim && b[i].y > lim2 && b[i].id == P[3]) {
      r++;
    }
  if (r < x) return 0;
  return 1;
}
int prt2(int x) {
  int r = 0, i = 1, lim, lim2;
  for (; i <= n && r < x; i++)
    if (a[i].id == P[1]) {
      printf("%d ", a[i].o);
      r++, lim = a[i].x;
    }
  if (r < x) return 0;
  r = 0;
  for (i = 1; i <= n && r < x; i++)
    if (b[i].x > lim && b[i].id == P[2]) {
      printf("%d ", b[i].o);
      r++, lim2 = b[i].y;
    }
  if (r < x) return 0;
  r = 0;
  for (; i <= n && r < x; i++)
    if (b[i].x > lim && b[i].y > lim2 && b[i].id == P[3]) {
      printf("%d ", b[i].o);
      r++;
    }
}
int chk3(int x) {
  int r = 0, i = 1, lim, lim2;
  for (i = n; i && r < x; i--)
    if (a[i].id == P[1]) {
      r++, lim = a[i].x;
    }
  if (r < x) return 0;
  r = 0;
  for (i = 1; i <= n && r < x; i++)
    if (b[i].x < lim && b[i].id == P[2]) {
      r++, lim2 = b[i].y;
    }
  if (r < x) return 0;
  r = 0;
  for (; i <= n && r < x; i++)
    if (b[i].x < lim && b[i].y > lim2 && b[i].id == P[3]) {
      r++;
    }
  if (r < x) return 0;
  return 1;
}
int prt3(int x) {
  int r = 0, i = 1, lim, lim2;
  for (i = n; i && r < x; i--)
    if (a[i].id == P[1]) {
      printf("%d ", a[i].o);
      r++, lim = a[i].x;
    }
  if (r < x) return 0;
  r = 0;
  for (i = 1; i <= n && r < x; i++)
    if (b[i].x < lim && b[i].id == P[2]) {
      printf("%d ", b[i].o);
      r++, lim2 = b[i].y;
    }
  if (r < x) return 0;
  r = 0;
  for (; i <= n && r < x; i++)
    if (b[i].x < lim && b[i].y > lim2 && b[i].id == P[3]) {
      printf("%d ", b[i].o);
      r++;
    }
}
int chk5(int x) {
  int r = 0, i = 1, lim, lim2;
  for (; i <= n && r < x; i++)
    if (b[i].id == P[1]) {
      r++, lim = b[i].y;
    }
  if (r < x) return 0;
  r = 0;
  for (i = 1; i <= n && r < x; i++)
    if (a[i].y > lim && a[i].id == P[2]) {
      r++, lim2 = a[i].x;
    }
  if (r < x) return 0;
  r = 0;
  for (; i <= n && r < x; i++)
    if (a[i].y > lim && a[i].x > lim2 && a[i].id == P[3]) {
      r++;
    }
  if (r < x) return 0;
  return 1;
}
int prt5(int x) {
  int r = 0, i = 1, lim, lim2;
  for (; i <= n && r < x; i++)
    if (b[i].id == P[1]) {
      printf("%d ", b[i].o);
      r++, lim = b[i].y;
    }
  if (r < x) return 0;
  r = 0;
  for (i = 1; i <= n && r < x; i++)
    if (a[i].y > lim && a[i].id == P[2]) {
      printf("%d ", a[i].o);
      r++, lim2 = a[i].x;
    }
  if (r < x) return 0;
  r = 0;
  for (; i <= n && r < x; i++)
    if (a[i].y > lim && a[i].x > lim2 && a[i].id == P[3]) {
      printf("%d ", a[i].o);
      r++;
    }
}
int chk6(int x) {
  int r = 0, i = 1, lim, lim2;
  for (i = n; i && r < x; i--)
    if (b[i].id == P[1]) {
      r++, lim = b[i].y;
    }
  if (r < x) return 0;
  r = 0;
  for (i = 1; i <= n && r < x; i++)
    if (a[i].y < lim && a[i].id == P[2]) {
      r++, lim2 = a[i].x;
    }
  if (r < x) return 0;
  r = 0;
  for (; i <= n && r < x; i++)
    if (a[i].y < lim && a[i].x > lim2 && a[i].id == P[3]) {
      r++;
    }
  if (r < x) return 0;
  return 1;
}
int prt6(int x) {
  int r = 0, i = 1, lim, lim2;
  for (i = n; i && r < x; i--)
    if (b[i].id == P[1]) {
      printf("%d ", b[i].o);
      r++, lim = b[i].y;
    }
  if (r < x) return 0;
  r = 0;
  for (i = 1; i <= n && r < x; i++)
    if (a[i].y < lim && a[i].id == P[2]) {
      printf("%d ", a[i].o);
      r++, lim2 = a[i].x;
    }
  if (r < x) return 0;
  r = 0;
  for (; i <= n && r < x; i++)
    if (a[i].y < lim && a[i].x > lim2 && a[i].id == P[3]) {
      printf("%d ", a[i].o);
      r++;
    }
}
int main() {
  int i;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].id);
    a[i].o = i;
    b[i] = a[i];
  }
  sort(a + 1, a + n + 1, cmpx);
  sort(b + 1, b + n + 1, cmpy);
  int l = 1, r = n, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1, flg = 0;
    P[1] = 1;
    P[2] = 2;
    P[3] = 3;
    flg |=
        chk1(mid) | chk2(mid) | chk3(mid) | chk4(mid) | chk5(mid) | chk6(mid);
    P[1] = 1;
    P[2] = 3;
    P[3] = 2;
    flg |=
        chk1(mid) | chk2(mid) | chk3(mid) | chk4(mid) | chk5(mid) | chk6(mid);
    P[1] = 2;
    P[2] = 1;
    P[3] = 3;
    flg |=
        chk1(mid) | chk2(mid) | chk3(mid) | chk4(mid) | chk5(mid) | chk6(mid);
    P[1] = 2;
    P[2] = 3;
    P[3] = 1;
    flg |=
        chk1(mid) | chk2(mid) | chk3(mid) | chk4(mid) | chk5(mid) | chk6(mid);
    P[1] = 3;
    P[2] = 1;
    P[3] = 2;
    flg |=
        chk1(mid) | chk2(mid) | chk3(mid) | chk4(mid) | chk5(mid) | chk6(mid);
    P[1] = 3;
    P[2] = 2;
    P[3] = 1;
    flg |=
        chk1(mid) | chk2(mid) | chk3(mid) | chk4(mid) | chk5(mid) | chk6(mid);
    if (flg)
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  printf("%d\n", 3 * ans);
  int mid = ans, flg;
  P[1] = 1;
  P[2] = 2;
  P[3] = 3;
  if (chk1(ans)) {
    prt1(ans);
    return 0;
  }
  if (chk2(ans)) {
    prt2(ans);
    return 0;
  }
  if (chk3(ans)) {
    prt3(ans);
    return 0;
  }
  if (chk4(ans)) {
    prt4(ans);
    return 0;
  }
  if (chk5(ans)) {
    prt5(ans);
    return 0;
  }
  if (chk6(ans)) {
    prt6(ans);
    return 0;
  }
  P[1] = 1;
  P[2] = 3;
  P[3] = 2;
  if (chk1(ans)) {
    prt1(ans);
    return 0;
  }
  if (chk2(ans)) {
    prt2(ans);
    return 0;
  }
  if (chk3(ans)) {
    prt3(ans);
    return 0;
  }
  if (chk4(ans)) {
    prt4(ans);
    return 0;
  }
  if (chk5(ans)) {
    prt5(ans);
    return 0;
  }
  if (chk6(ans)) {
    prt6(ans);
    return 0;
  }
  P[1] = 2;
  P[2] = 1;
  P[3] = 3;
  if (chk1(ans)) {
    prt1(ans);
    return 0;
  }
  if (chk2(ans)) {
    prt2(ans);
    return 0;
  }
  if (chk3(ans)) {
    prt3(ans);
    return 0;
  }
  if (chk4(ans)) {
    prt4(ans);
    return 0;
  }
  if (chk5(ans)) {
    prt5(ans);
    return 0;
  }
  if (chk6(ans)) {
    prt6(ans);
    return 0;
  }
  P[1] = 2;
  P[2] = 3;
  P[3] = 1;
  if (chk1(ans)) {
    prt1(ans);
    return 0;
  }
  if (chk2(ans)) {
    prt2(ans);
    return 0;
  }
  if (chk3(ans)) {
    prt3(ans);
    return 0;
  }
  if (chk4(ans)) {
    prt4(ans);
    return 0;
  }
  if (chk5(ans)) {
    prt5(ans);
    return 0;
  }
  if (chk6(ans)) {
    prt6(ans);
    return 0;
  }
  P[1] = 3;
  P[2] = 1;
  P[3] = 2;
  if (chk1(ans)) {
    prt1(ans);
    return 0;
  }
  if (chk2(ans)) {
    prt2(ans);
    return 0;
  }
  if (chk3(ans)) {
    prt3(ans);
    return 0;
  }
  if (chk4(ans)) {
    prt4(ans);
    return 0;
  }
  if (chk5(ans)) {
    prt5(ans);
    return 0;
  }
  if (chk6(ans)) {
    prt6(ans);
    return 0;
  }
  P[1] = 3;
  P[2] = 2;
  P[3] = 1;
  if (chk1(ans)) {
    prt1(ans);
    return 0;
  }
  if (chk2(ans)) {
    prt2(ans);
    return 0;
  }
  if (chk3(ans)) {
    prt3(ans);
    return 0;
  }
  if (chk4(ans)) {
    prt4(ans);
    return 0;
  }
  if (chk5(ans)) {
    prt5(ans);
    return 0;
  }
  if (chk6(ans)) {
    prt6(ans);
    return 0;
  }
}
