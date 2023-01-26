#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && (c != '-')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
int main() {
  int T = read();
  while (T--) {
    long long s = read(), n = read(), k = read();
    if (s == k) {
      puts("YES");
      continue;
    }
    long long cnt = s % k;
    long long ans = ((s / k + 1) / 2) * (k - cnt) + (s / k + 2) / 2 * cnt;
    ans -= (s / k + 1) / 2;
    ans += s / k / 2;
    puts(ans >= n ? "NO" : "YES");
  }
}
