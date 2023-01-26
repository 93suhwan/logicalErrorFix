#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int b = 1, sum = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') b = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return b * sum;
}
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int M = 1e6 + 10;
int n, m, T, s;
int main() {
  int i, j;
  T = read();
  while (T--) {
    int ans = 0;
    n = read(), s = read();
    int q = (n + 1) / 2;
    q -= 1;
    n -= q;
    ans = s / n;
    printf("%d", ans);
    puts("");
  }
  return 0;
}
