#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,popcnt")
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  char c, f = 1;
  for (c = getchar(); c < '0' || c > '9'; c = getchar())
    if (c == '-') f = 0;
  for (; c >= '0' && c <= '9'; c = getchar())
    x = (((x << 2) + x) << 1) + (c ^ '0');
  x = f ? x : -x;
}
template <typename T, typename... Args>
void read(T &t, Args &...args) {
  read(t);
  read(args...);
}
long long read() {
  long long x;
  read(x);
  return x;
}
const int maxn = 2e3 + 5;
int num[maxn], dp[maxn];
void solve() {
  int n, k;
  read(n, k);
  for (int i = (1); i <= (n); i++) read(num[i]), num[i] = i - num[i];
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  for (int i = (1); i <= (n); i++)
    if (num[i] >= 0)
      for (int j = min(k, i - num[i]); j; j--)
        if (num[i] >= dp[j - 1]) dp[j] = min(dp[j], num[i]);
  printf("%d\n", dp[k] == 0x3f3f3f3f ? -1 : dp[k]);
}
int main() {
  int T;
  if (1)
    read(T);
  else
    T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
