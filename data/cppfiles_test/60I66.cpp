#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long mod1 = 998244353;
long long fastpower(long long base, long long power) {
  long long res = 1;
  while (power > 0) {
    if (power & 1) res = res * base % mod;
    power >>= 1;
    base = base * base % mod;
  }
  return res;
}
long long t, n, a[1000000];
int main() {
  scanf("%lld", &t);
  while (t--) {
    long long cnt = 0;
    long long sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < n; i++) sum += a[i];
    long long s = sum / n;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        if (a[i] + a[j] == s * 2) cnt++;
      }
    printf("%lld\n", cnt);
  }
  return 0;
}
