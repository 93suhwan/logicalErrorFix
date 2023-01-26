#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x7fffffff;
inline void swap(int &x, int &y) { x ^= y ^= x ^= y; }
inline int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
int dp[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= 512; ++i) dp[i] = INF;
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    for (int j = 0; j <= 512; ++j) {
      if (x > dp[j]) dp[j ^ x] = min(dp[j ^ x], x);
    }
  }
  int cnt = 0;
  for (int i = 0; i <= 512; ++i)
    if (dp[i] != INF) cnt++;
  printf("%d\n", cnt);
  for (int i = 0; i <= 512; ++i) {
    if (dp[i] != INF) printf("%d ", i);
  }
  return 0;
}
