#include <bits/stdc++.h>
const int inf = 1e8 + 7;
int f[255];
int min(int a, int b) { return a > b ? b : a; }
int main() {
  f[0] = 0;
  for (int i = 1; i < 120; i++) {
    f[i] = inf;
    int last = i - 6;
    if (last < 0) last = 0;
    f[i] = min(f[i], f[last] + 15);
    last = i - 8;
    if (last < 0) last = 0;
    f[i] = min(f[i], f[last] + 20);
    last = i - 10;
    if (last < 0) last = 0;
    f[i] = min(f[i], f[last] + 25);
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    long long n;
    scanf("%lld", &n);
    long long mod = 120;
    long long all = (n - n % mod) / mod;
    long long left = n % mod;
    printf("%lld\n", all * 300ll + (long long)f[left]);
  }
  return 0;
}
