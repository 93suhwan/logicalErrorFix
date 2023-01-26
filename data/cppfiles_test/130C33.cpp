#include <bits/stdc++.h>
using namespace std;
int a[3], b[3];
int zt[10005];
set<int> zd, jd;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, tt;
    scanf("%d", &n);
    zd.clear(), jd.clear();
    int nn = n / 3;
    for (int i = 1; i <= nn; ++i) zt[i] = -1;
    for (int i = 1; i <= nn; ++i) {
      printf("? %d %d %d\n", i * 3, i * 3 - 1, i * 3 - 2);
      fflush(stdout);
      scanf("%d", &tt);
      zt[i] = tt;
      if (tt)
        a[0] = i * 3 - 2, a[1] = a[0] + 1, a[2] = a[0] + 2;
      else
        b[0] = i * 3 - 2, b[1] = b[0] + 1, b[2] = b[0] + 2;
    }
    int zz, jj;
    int a0 = -1, a1 = -1, a2 = -1;
    printf("? %d %d %d\n", b[0], b[1], a[0]);
    fflush(stdout);
    scanf("%d", &a0);
    printf("? %d %d %d\n", b[0], b[1], a[1]);
    fflush(stdout);
    scanf("%d", &a1);
    printf("? %d %d %d\n", b[0], b[1], a[2]);
    fflush(stdout);
    scanf("%d", &a2);
    int sm = a0 + a1 + a2;
    if (sm == 0) {
      jd.insert(b[0]), jd.insert(b[1]);
      printf("? %d %d %d\n", b[0], a[1], a[0]);
      fflush(stdout);
      scanf("%d", &tt);
      if (tt) {
        zd.insert(a[1]), zd.insert(a[0]);
        printf("? %d %d %d\n", b[0], a[1], a[2]);
        fflush(stdout);
        scanf("%d", &tt);
        if (tt)
          zd.insert(a[2]);
        else
          jd.insert(a[2]);
        printf("? %d %d %d\n", b[0], a[1], b[2]);
        fflush(stdout);
        scanf("%d", &tt);
        if (tt)
          zd.insert(b[2]);
        else
          jd.insert(b[2]);
      } else {
        zd.insert(a[2]);
        printf("? %d %d %d\n", a[2], b[0], a[0]);
        fflush(stdout);
        scanf("%d", &tt);
        if (tt)
          zd.insert(a[0]), jd.insert(a[1]);
        else
          zd.insert(a[1]), jd.insert(a[0]);
        printf("? %d %d %d\n", b[0], a[2], b[2]);
        fflush(stdout);
        scanf("%d", &tt);
        if (tt)
          zd.insert(b[2]);
        else
          jd.insert(b[2]);
      }
      zz = *zd.begin(), jj = *jd.begin();
    } else {
      if (sm == 2) {
        jd.insert(b[2]);
        if (a0)
          zd.insert(a[0]);
        else
          jd.insert(a[0]);
        if (a1)
          zd.insert(a[1]);
        else
          jd.insert(a[1]);
        if (a2)
          zd.insert(a[2]);
        else
          jd.insert(a[2]);
      } else if (sm == 3) {
        zd.insert(a[0]);
        zd.insert(a[1]);
        zd.insert(a[2]);
        jd.insert(b[2]);
      }
      zz = *zd.begin(), jj = *jd.begin();
      printf("? %d %d %d\n", zz, jj, b[0]);
      fflush(stdout);
      scanf("%d", &tt);
      if (tt)
        zd.insert(b[0]), jd.insert(b[1]);
      else
        zd.insert(b[1]), jd.insert(b[0]);
    }
    for (int i = 1; i <= nn; ++i) {
      if (i * 3 == a[2] || i * 3 == b[2]) continue;
      a0 = i * 3 - 2, a1 = i * 3 - 1, a2 = i * 3;
      if (zt[i]) {
        printf("? %d %d %d\n", jj, a0, a1);
        fflush(stdout);
        scanf("%d", &tt);
        if (tt) {
          zd.insert(a0), zd.insert(a1);
          printf("? %d %d %d\n", zz, jj, a2);
          fflush(stdout);
          scanf("%d", &tt);
          if (tt)
            zd.insert(a2);
          else
            jd.insert(a2);
        } else {
          zd.insert(a2);
          printf("? %d %d %d\n", zz, jj, a0);
          fflush(stdout);
          scanf("%d", &tt);
          if (tt)
            zd.insert(a0), jd.insert(a1);
          else
            jd.insert(a0), zd.insert(a1);
        }
      } else {
        printf("? %d %d %d\n", zz, a0, a1);
        fflush(stdout);
        scanf("%d", &tt);
        if (tt == 0) {
          jd.insert(a0), jd.insert(a1);
          printf("? %d %d %d\n", zz, jj, a2);
          fflush(stdout);
          scanf("%d", &tt);
          if (tt)
            zd.insert(a2);
          else
            jd.insert(a2);
        } else {
          jd.insert(a2);
          printf("? %d %d %d\n", zz, jj, a0);
          fflush(stdout);
          scanf("%d", &tt);
          if (tt)
            zd.insert(a0), jd.insert(a1);
          else
            jd.insert(a0), zd.insert(a1);
        }
      }
    }
    printf("! %d", jd.size());
    for (auto it = jd.begin(); it != jd.end(); ++it) printf(" %d", *it);
    puts("");
    fflush(stdout);
  }
  return 0;
}
