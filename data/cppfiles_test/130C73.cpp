#include <bits/stdc++.h>
using namespace std;
const int NR = 1e4 + 10;
int T, n;
int s[NR], a[NR], z[NR], ta;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int x = 1, last = -1, p = 0, q = 0;
    ta = 0;
    while (x <= n) {
      printf("? %d %d %d\n", x, x + 1, x + 2);
      fflush(stdout);
      scanf("%d", &s[x]);
      s[x + 1] = s[x];
      s[x + 2] = s[x];
      if (last != -1 && s[x] != last && p == 0) {
        int id1, id2;
        printf("? %d %d %d\n", x - 2, x - 1, x);
        fflush(stdout);
        scanf("%d", &id1);
        printf("? %d %d %d\n", x - 1, x, x + 1);
        fflush(stdout);
        scanf("%d", &id2);
        if (id1 != s[x - 1]) {
          p = x - 3;
          q = x;
          if (!s[x - 1])
            p = x - 3, q = x;
          else
            p = x, q = x - 3;
          z[++ta] = p;
        } else if (id1 != id2) {
          if (!id1)
            p = x - 2, q = x + 1;
          else
            p = x + 1, q = x - 2;
          z[++ta] = p;
        } else {
          if (!id2)
            p = x - 1, q = x + 2;
          else
            p = x + 2, q = x - 1;
          z[++ta] = p;
        }
      }
      last = s[x];
      x += 3;
    }
    x = 1;
    while (x <= n) {
      if (x == p || x + 1 == p || x + 2 == p || x == q || x + 1 == q ||
          x + 2 == q) {
        for (int i = 0; i <= 2; i++) {
          if (x + i != p && x + i != q) {
            printf("? %d %d %d\n", x + i, p, q);
            fflush(stdout);
            int id;
            scanf("%d", &id);
            if (!id) z[++ta] = x + i;
          }
        }
      } else {
        int id1, id2;
        if (!s[x]) {
          printf("? %d %d %d\n", x, x + 1, q);
          fflush(stdout);
          scanf("%d", &id1);
          printf("? %d %d %d\n", x + 1, x + 2, q);
          fflush(stdout);
          scanf("%d", &id2);
        } else {
          printf("? %d %d %d\n", x, x + 1, p);
          fflush(stdout);
          scanf("%d", &id1);
          printf("? %d %d %d\n", x + 1, x + 2, p);
          fflush(stdout);
          scanf("%d", &id2);
        }
        if (s[x] == 0 && id1 == 0 && id2 == 0)
          z[++ta] = x, z[++ta] = x + 1, z[++ta] = x + 2;
        if (s[x] == 0 && id1 == 0 && id2 == 1) z[++ta] = x, z[++ta] = x + 1;
        if (s[x] == 0 && id1 == 1 && id2 == 0) z[++ta] = x + 1, z[++ta] = x + 2;
        if (s[x] == 0 && id1 == 1 && id2 == 1) z[++ta] = x, z[++ta] = x + 2;
        if (s[x] == 1 && id1 == 0 && id2 == 0) z[++ta] = x + 1;
        if (s[x] == 1 && id1 == 0 && id2 == 1) z[++ta] = x;
        if (s[x] == 1 && id1 == 1 && id2 == 0) z[++ta] = x + 2;
      }
      x += 3;
    }
    printf("! %d ", ta);
    for (int i = 1; i <= ta; i++) printf("%d ", z[i]);
    puts("");
    fflush(stdout);
  }
  return 0;
}
