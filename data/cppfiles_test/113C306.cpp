#include <bits/stdc++.h>
using namespace std;
long long ksm(long long x, long long n = 998244353 - 2) {
  x %= 998244353;
  long long res = 1;
  while (n) {
    if (n & 1) res *= x;
    res %= 998244353;
    x *= x;
    x %= 998244353;
    n >>= 1;
  }
  return res % 998244353;
}
void slv() {
  int x1, p1, x2, p2;
  scanf("%d%d%d%d", &x1, &p1, &x2, &p2);
  if (p1 > p2) {
    p1 -= p2;
    p2 = 0;
  } else {
    p2 -= p1;
    p1 = 0;
  }
  int pos1 = log10(x1) + p1, pos2 = log10(x2) + p2;
  if (pos1 > pos2)
    printf(">");
  else if (pos1 < pos2)
    printf("<");
  else {
    long long xx1 = x1 * pow(10, p1), xx2 = x2 * pow(10, p2);
    if (xx1 > xx2)
      printf(">");
    else if (xx1 < xx2)
      printf("<");
    else
      printf("=");
  }
}
int main() {
  int _ = 1;
  scanf("%d", &_);
  for (int i = 1; i <= _; i++) {
    slv();
    printf("\n");
  }
  return 0;
}
