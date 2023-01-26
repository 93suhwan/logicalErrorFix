#include <bits/stdc++.h>
inline long long read() {
  long long num = 0, f = 1;
  char c = getchar();
  while (c < 48 || c > 57) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c > 47 && c < 58) num = num * 10 + (c ^ 48), c = getchar();
  return num * f;
}
inline long long re1d() {
  char c = getchar();
  while (c < 48 || c > 49) c = getchar();
  return c & 1;
}
inline long long min(long long a, long long b) { return a > b ? b : a; }
inline long long max(long long a, long long b) { return a < b ? b : a; }
long long X = 1000000000;
signed main() {
  printf("? %lld %lld\n", 1, 1);
  fflush(stdout);
  long long A = read();
  printf("? %lld %lld\n", 1, X);
  fflush(stdout);
  long long B = read();
  printf("? %lld %lld\n", X, 1);
  fflush(stdout);
  long long C = read();
  printf("? %lld %lld\n", X, X);
  fflush(stdout);
  long long D = read();
  A += 2;
  B = X - B - 1;
  C = X - C - 1;
  D = X + X - D;
  long long E = A + B;
  long long F = A + C;
  long long MidR = E >> 1, MidC = F >> 1;
  printf("? %lld %lld\n", MidR, 1);
  fflush(stdout);
  long long left = read() + 1;
  printf("? %lld %lld\n", MidR, X);
  fflush(stdout);
  long long rigt = X - read();
  printf("? %lld %lld\n", 1, MidC);
  fflush(stdout);
  long long up = read() + 1;
  printf("? %lld %lld\n", X, MidC);
  fflush(stdout);
  long long down = X - read();
  printf("! %lld %lld %lld %lld\n", up, left, down, rigt);
  return 0;
}
