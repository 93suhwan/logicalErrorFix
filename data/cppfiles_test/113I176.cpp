#include <bits/stdc++.h>
using namespace std;
inline bool scan_d(int& num) {
  char in;
  bool IsN = false;
  in = getchar();
  if (in == EOF) return false;
  while (in != '-' && (in < '0' || in > '9')) in = getchar();
  if (in == '-') {
    IsN = true;
    num = 0;
  } else
    num = in - '0';
  while (in = getchar(), in >= '0' && in <= '9') {
    num *= 10, num += in - '0';
  }
  if (IsN) num = -num;
  return true;
}
int t, x1, x2, p1, p2;
int main() {
  scan_d(t);
  while (t--) {
    scan_d(x1), scan_d(p1);
    scan_d(x2), scan_d(p2);
    int k1 = 0, k2 = 0;
    int d1 = x1, d2 = x2;
    while (x1) {
      x1 /= 10;
      k1++;
    }
    while (x2) {
      x2 /= 10;
      k2++;
    }
    if (k1 + p1 != k2 + p2)
      printf("%c\n", (k1 + p1) > (k2 + p2) ? '>' : '<');
    else {
      if (k1 > k2) {
        while (k2 < k1) {
          k2++;
          d2 *= 10;
        }
        if (d1 == d2)
          puts("=");
        else
          printf("%c\n", (d1) > (d2) ? '>' : '<');
      } else if (k1 < k2) {
        while (k1 < k2) {
          k1++;
          d1 *= 10;
        }
        if (d1 == d2)
          puts("=");
        else
          printf("%c\n", (d1) > (d2) ? '>' : '<');
      } else
        puts("=");
    }
  }
  return 0;
}
