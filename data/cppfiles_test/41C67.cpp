#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 9;
const int M = 1e3 + 9;
int n, k, T;
int ans, val;
int pw[N];
int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = (x << 1) + (x << 3) + (s ^ '0');
    s = getchar();
  }
  return f * x;
}
int main() {
  n = read();
  k = read();
  for (int i = 1; i <= n; i++) T = 1;
  pw[1] = 1;
  while (1) {
    pw[T] *= k;
    if (pw[T] >= n) break;
    T++;
    pw[T] = pw[T - 1];
  }
  printf("%d\n", T);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      for (int l = 1; l <= T; l++)
        if ((j - 1) / pw[l] == (i - 1) / pw[l]) {
          printf("%d ", l);
          break;
        }
    }
  return 0;
}
