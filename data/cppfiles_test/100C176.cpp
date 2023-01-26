#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
void chkmax(long long &a, long long b) {
  if (a < b) a = b;
}
void chkmin(long long &a, long long b) {
  if (a > b) a = b;
}
long long qpow(long long d, long long z) {
  long long res = 1;
  for (; z; z >>= 1) {
    if (z & 1) res = res * d % MOD;
    d = d * d % MOD;
  }
  return res;
}
int n;
int d[200005];
void solve() {
  scanf("%d", &n);
  int Max = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &d[i]);
    if (Max < d[i]) Max = d[i];
  }
  int cM0 = 0, cM1 = 0;
  for (int i = 1; i <= n; i++) {
    if (d[i] == Max)
      cM0++;
    else if (d[i] + 1 == Max)
      cM1++;
  }
  long long ff = 1;
  for (int i = 1; i <= n; i++) ff = ff * i % MOD;
  assert(cM0 >= 1);
  if (cM0 >= 2) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) ans = ans * i % MOD;
    printf("%lld\n", ans);
  } else if (cM1 == 0) {
    printf("0\n");
  } else {
    long long ans = 1;
    for (int i = 0; i < cM1 + 1; i++) ans = ans * (n - i) % MOD;
    for (int i = 1; i <= n - cM1 - 1; i++) ans = ans * i % MOD;
    ans = ans * qpow(cM1 + 1, MOD - 2) % MOD;
    ans = (ff - ans + MOD) % MOD;
    printf("%lld\n", ans);
  }
  return;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
