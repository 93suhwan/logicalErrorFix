#include <bits/stdc++.h>
using namespace std;
char gc() {
  static char buf[1 << 16], *s, *t;
  if (s == t) {
    t = (s = buf) + fread(buf, 1, 1 << 16, stdin);
    if (s == t) return EOF;
  }
  return *s++;
}
int read() {
  char c;
  int w = 1;
  while ((c = getchar()) > '9' || c < '0')
    if (c == '-') w = -1;
  int ans = c - '0';
  while ((c = getchar()) >= '0' && c <= '9')
    ans = (ans << 1) + (ans << 3) + c - '0';
  return ans * w;
}
void pc(char c, int op) {
  static char buf[1 << 16], *s = buf, *t = buf + (1 << 16);
  (op || ((*s++ = c) && s == t)) &&
      ((fwrite(buf, 1, s - buf, stdout)), s = buf);
}
void wt(int x) {
  if (x > 9) wt(x / 10);
  pc('0' + x % 10, 0);
}
void wts(int x, char op) {
  if (x < 0) pc('-', 0), x = -x;
  wt(x);
  pc(op, 0);
}
int main() {
  int T = read();
  while (T--) {
    int a = read(), b = read(), c = read();
    if ((a + b + c) % 2) {
      puts("NO");
    } else
      puts("YES");
  }
  pc('1', 1);
  return 0;
}
