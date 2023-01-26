#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
int T, n, dp[100][100];
int fuckpow(int x, int y) {
  int ans = 1;
  for (; y; y >>= 1) {
    if (y & 1) ans = (long long)ans * x % Mod;
    x = (long long)x * x % Mod;
  }
  return ans;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    n <<= 1;
    int ans = 1;
    for (int i = 2; i <= n; i++) ans = (long long)ans * i % Mod;
    printf("%lld\n", (long long)ans * fuckpow(2, Mod - 2) % Mod);
  }
  return 0;
}
