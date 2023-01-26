#include <bits/stdc++.h>
typedef struct {
  long r, pos;
  bool like;
} song;
int cfunc1(song &a, song &b) {
  if (a.like == b.like)
    return a.r < b.r;
  else
    return a.like < b.like;
}
int cfunc2(song &a, song &b) { return a.pos < b.pos; }
int main() {
  long t, n, x;
  char c;
  song a[200000];
  scanf("%ld", &t);
  for (long f = 0; f < t; f++) {
    scanf("%ld", &n);
    for (long i = 0; i < n; i++) {
      scanf("%ld", &x);
      a[i].pos = i;
      a[i].r = x;
    }
    scanf("%*c");
    for (long i = 0; i < n; i++) {
      scanf("%c", &c);
      if (c == '1')
        a[i].like = 1;
      else
        a[i].like = 0;
    }
    std::sort(a, a + n, cfunc1);
    for (long i = 0; i < n; i++) a[i].r = i + 1;
    std::sort(a, a + n, cfunc2);
    for (long i = 0; i < n; i++) printf("%ld ", a[i].r);
    printf("\n");
  }
}
