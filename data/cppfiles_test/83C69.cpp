#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
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
int dp[N], in[N], col[N];
vector<int> v[N];
int lcp[5050][5050];
int main() {
  re(t);
  while (t--) {
    re(n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) in[i] = s[i];
    for (int i = 0; i <= n; i++) lcp[i][n] = lcp[n][i] = 0;
    for (int i = n - 1; i >= 0; i--)
      for (int j = n - 1; j >= 0; j--)
        lcp[i][j] = s[i] == s[j] ? lcp[i + 1][j + 1] + 1 : 0;
    for (int i = 0; i < 26; i++) v[i].clear(), col[i] = 0;
    for (int i = 0; i < n; i++) dp[i] = 0;
    for (int i = 0; i < n; i++) {
      int now = s[i] - 'a';
      dp[i] = n - i;
      for (int j : v[now]) {
        int l = lcp[i][j];
        if (i + l >= n) continue;
        if (s[i + l] < s[j + l]) continue;
        dp[i] = max(dp[i], dp[j] + n - i - l);
      }
      v[now].push_back(i);
      for (int j = 0; j < now; j++)
        if (dp[i] <= col[j] + n - i) dp[i] = col[j] + n - i;
      col[now] = max(col[now], dp[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, dp[i]);
    printf("%d\n", ans);
  }
}
