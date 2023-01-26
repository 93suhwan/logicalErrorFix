#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
  return x * f;
}
inline void out(int x) {
  if (x > 9) out(x / 10);
  putchar(x % 10 ^ 48);
}
inline void print(int x) {
  if (x < 0) putchar('-'), x = -x;
  out(x), puts("");
};
const int N = 5005, p = 998244353;
char s[N];
long long jc[N], inv[N];
inline int spow(long long x, int y, long long res = 1) {
  while (y) {
    if (y & 1) (res *= x) %= p;
    (x *= x) %= p, y >>= 1;
  }
  return res % p;
}
inline int C(int x, int y) { return jc[x] * inv[y] % p * inv[x - y] % p; }
int sum[N];
void solve() {
  int n = read(), k = read(), ans = 1;
  scanf("%s", s + 1), jc[0] = 1;
  for (int i = 1; i <= n; i++)
    sum[i] = sum[i - 1] + s[i] - 48, jc[i] = jc[i - 1] * i % p;
  inv[n] = spow(jc[n], p - 2);
  for (int i = n - 1; ~i; i--) inv[i] = inv[i + 1] * (i + 1) % p;
  if (sum[n] < k) return (void)puts("1");
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      int cnt = sum[j] - sum[i - 1];
      if (cnt <= k) {
        if (s[i] == '0') cnt--;
        if (s[j] == '0') cnt--;
        if (cnt >= 0 && cnt <= j - i - 1) (ans += C(j - i - 1, cnt)) %= p;
      }
    }
  cout << ans;
}
int main() {
  int T = 1;
  while (T--) solve();
}
