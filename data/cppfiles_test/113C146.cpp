#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int s = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') s = s * 10 + c - '0', c = getchar();
  return s * f;
}
void write(int x) {
  if (x < 0) {
    putchar('-');
    write(-x);
  } else {
    if (x > 9) write(x / 10);
    putchar(x % 10 | 48);
  }
}
int a, b, p1, p2, w1, w2;
void work() {
  a = read();
  p1 = read();
  b = read();
  p2 = read();
  int c = a, d = b;
  w1 = 0, w2 = 0;
  while (c) {
    w1++;
    c /= 10;
  }
  while (d) {
    w2++;
    d /= 10;
  }
  w1 += p1, w2 += p2;
  if (w1 > w2) {
    printf(">\n");
    return;
  }
  if (w1 < w2) {
    printf("<\n");
    return;
  }
  if (p1 > p2)
    for (int i = 1; i <= p1 - p2; i++) a *= 10;
  if (p1 < p2)
    for (int i = 1; i <= p2 - p1; i++) b *= 10;
  if (a < b) printf("<\n");
  if (a > b) printf(">\n");
  if (a == b) printf("=\n");
}
int main() {
  int t = read();
  while (t--) work();
  return 0;
}
