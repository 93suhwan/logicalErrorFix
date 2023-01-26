#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const long long mod = 1e9 + 7;
inline long long gcd(long long a, long long b) {
  return !b ? a : gcd(b, a % b);
}
inline long long q_pow(long long a, long long x = mod - 2) {
  long long ans = 1, tmp = a;
  while (x) {
    if (x & 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    x >>= 1;
  }
  return ans;
}
template <typename T>
inline void re(T &N) {
  int f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  N = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') N = N * 10 + c - '0';
  N *= f;
}
template <class T, class... T_>
inline void re(T &x, T_ &...y) {
  re(x), re(y...);
}
int m, n, t = 1, st, en;
char s[N];
int dp[N], la[N];
int main() {
  re(t);
  while (t--) {
    re(n);
    scanf("%s", s + 1);
    for (int i = 0; i < 26; i++) dp[i] = la[i] = 0;
    for (int i = 1; i <= n; i++) {
      int now = s[i] - 'a';
      if (la[now]) {
        for (int j = 0; i + j <= n; j++) {
          if (s[la[now] + j] < s[i + j]) {
            dp[now] += n - i - j + 1;
            la[now] = i;
            break;
          }
          if (s[la[now] + j] > s[i + j]) break;
        }
      } else {
        dp[now] = n - i + 1;
        la[now] = i;
      }
      for (int j = 0; j < now; j++)
        if (dp[now] <= dp[j] + n - i + 1) {
          dp[now] = dp[j] + n - i + 1;
          la[now] = i;
        }
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) ans = max(ans, dp[i]);
    printf("%d\n", ans);
  }
}
