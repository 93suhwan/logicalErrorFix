#include <bits/stdc++.h>
using namespace std;
inline int rd() {
  int x = 0;
  char ch, t = 0;
  while (!isdigit(ch = getchar())) t |= ch == '-';
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return x = t ? -x : x;
}
long long maxll(long long x, long long y) { return x > y ? x : y; }
long long minll(long long x, long long y) { return x < y ? x : y; }
long long absll(long long x) { return x > 0ll ? x : -x; }
long long gcd(long long x, long long y) { return (y == 0) ? x : gcd(y, x % y); }
int n, mod;
int sum, pre[8000005];
int main() {
  n = rd(), mod = rd();
  pre[2] = 1;
  for (int j = 2; j <= n; j++) {
    pre[j] = (pre[j] + 1) % mod;
    pre[j + j] = (pre[j + j] + mod - 1) % mod;
  }
  for (int i = 2, opt; i <= n; i++) {
    sum = (sum + pre[i]) % mod, opt = n / i;
    pre[i + 1] = (pre[i + 1] + sum) % mod;
    if (opt >= 2)
      for (int j = 2; j <= opt; j++) {
        pre[i * j] = (pre[i * j] + sum) % mod;
        pre[i * j + j] = (pre[i * j + j] + mod - sum) % mod;
      }
  }
  printf("%d\n", sum);
  return 0;
}
