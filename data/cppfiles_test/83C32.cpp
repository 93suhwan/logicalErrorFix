#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
inline long long read() {
  long long x = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c <= '9' && c >= '0') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return w == 1 ? x : -x;
}
unsigned long long h[1000005], b[1000005];
long long dp[1000005], n;
char s[1000005];
inline unsigned long long gh(int l, int r) {
  return h[r] - h[l - 1] * b[r - l + 1];
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    return write(-x);
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline int lcp(int x, int y) {
  int l = 0, r = n - y + 1, tmp = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (gh(x, x + mid - 1) == gh(y, y + mid - 1))
      tmp = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  return tmp;
}
int main() {
  b[0] = 1;
  for (int i = 1; i <= 1000005 - 5; i++) b[i] = b[i - 1] * 233;
  int T = read();
  while (T--) {
    n = read();
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
      h[i] = h[i - 1] * 233 + s[i], dp[i] = n - i + 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i - 1; j++) {
        int tmp = lcp(i, j);
        if (j + tmp + 1 > n) continue;
        if (s[j + tmp] < s[i + tmp])
          dp[i] = max(dp[i], dp[j] + n - i - tmp + 1);
      }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    cout << ans << endl;
  }
  return 0;
}
