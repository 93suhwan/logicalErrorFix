#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
int n;
struct Point {
  int x, y;
} p[6006];
unsigned long long d[6006][6006 / 64 + 5];
long long ans;
int cnt[4];
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    p[i].x = read() / 2, p[i].y = read() / 2;
    ++cnt[(p[i].x % 2) * 2 + p[i].y % 2];
  }
  long long ans = 1LL * n * (n - 1) * (n - 2) / 6;
  for (int i = 0; i < 4; ++i)
    for (int j = i + 1; j < 4; ++j)
      for (int k = j + 1; k < 4; ++k) ans -= 1LL * cnt[i] * cnt[j] * cnt[k];
  printf("%lld\n", ans);
  return 0;
}
