#include <bits/stdc++.h>
using namespace std;
int Max(int x, int y) { return x > y ? x : y; }
int Min(int x, int y) { return x < y ? x : y; }
void write(int x) {
  if (!x) {
    putchar('0');
    putchar('\n');
    return;
  }
  int c[20];
  c[0] = 0;
  while (x) {
    c[++c[0]] = x % 10;
    x /= 10;
  }
  for (int i = c[0]; i >= 1; --i) putchar(c[i] + '0');
  putchar('\n');
}
long long read() {
  long long u = 0, sig = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') sig = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    u = u * 10 + c - 48;
    c = getchar();
  }
  return u * sig;
}
int n;
int t;
int main() {
  t = read();
  while (t) {
    n = read();
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
      int a = read();
      sum += a;
    }
    if (sum % n == 0)
      cout << 0 << endl;
    else
      cout << 1 << endl;
    --t;
  }
  return 0;
}
