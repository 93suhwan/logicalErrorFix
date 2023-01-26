#include <bits/stdc++.h>
using namespace std;
char solve(int a, int b, int c, int d) {
  if (b == 0) a = 1;
  if (d == 0) c = 1;
  while (a % 10 == 0) {
    a /= 10;
    b++;
  }
  while (c % 10 == 0) {
    c /= 10;
    d++;
  }
  if (b != d) return b > d ? '>' : '<';
  if (a != c) return a > c ? '>' : '<';
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
