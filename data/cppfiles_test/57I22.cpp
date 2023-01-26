#include <bits/stdc++.h>
using namespace std;
inline void out(long long *a, long long l, long long r) {
  for (long long i = l; i <= r; ++i) printf("%d ", *(a + i));
  puts("");
}
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
signed main() {
  long long T = read();
  while (T--) {
    long long s = read(), n = read(), k = read();
    if (s == k)
      puts("Yes");
    else
      puts(((s / k + 1) / 2 * k + (!(s / k & 1)) * (s % k) >= n) ? "No"
                                                                 : "Yes");
  }
  return 0;
}
