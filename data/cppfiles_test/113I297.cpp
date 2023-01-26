#include <bits/stdc++.h>
using namespace std;
char solve(int a, int b, int c, int d) {
  int ra = 0, rc = 0, k = 1;
  k = 1;
  while (a > 10) {
    ra = ra + k * (a % 10);
    a /= 10;
    k *= 10;
    b++;
  }
  while (c > 10) {
    rc = rc + k * (c % 10);
    k *= 10;
    c /= 10;
    d++;
  }
  if (b != d) return b > d ? '>' : '<';
  if (a != c) return a > c ? '>' : '<';
  if (ra != rc) return ra > rc ? '>' : '<';
  return '=';
}
int main() {
  int T, a, b, c, d;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%c\n", solve(a, b, c, d));
  }
  return 0;
}
