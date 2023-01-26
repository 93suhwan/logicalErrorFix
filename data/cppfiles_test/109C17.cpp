#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const int MAXN = 200005;
long long qpow(long long d, long long z) {
  long long res = 1;
  for (; z; z >>= 1) {
    if (z & 1) res = res * d % MOD;
    d = d * d % MOD;
  }
  return res;
}
char op[7];
int main() {
  int n;
  scanf("%d", &n);
  long long pw = 1;
  int B = 0, W = 0;
  long long allBW = 1, allWB = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%s", op);
    for (int j = 0; j < 2; j++)
      if (op[j] == 'B')
        B++;
      else if (op[j] == 'W')
        W++;
    if (op[0] == 'W' || op[1] == 'B') allBW = 0;
    if (op[0] == 'B' || op[1] == 'W') allWB = 0;
    if (op[0] == op[1]) {
      if (op[0] == '?')
        pw = pw * 2 % MOD;
      else
        pw = 0;
    }
  }
  if (B > n || W > n) {
    printf("0\n");
    return 0;
  }
  long long ans = 1;
  long long ha = n + n - B - W + 1;
  for (int i = 1; i <= n - B; i++) {
    ans = ans * (ha - i) % MOD;
    ans = ans * qpow(i, MOD - 2) % MOD;
  }
  printf("%lld\n", ans - pw + allBW + allWB);
  return 0;
}
