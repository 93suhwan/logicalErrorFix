#include <bits/stdc++.h>
constexpr int Maxn = 2e5 + 7;
constexpr int Mod = 1e9 + 7;
int n, q, a[Maxn], s[Maxn], s2[Maxn], c[Maxn];
int fpm(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1LL * res * a % Mod;
    a = 1LL * a * a % Mod;
    b >>= 1;
  }
  return res;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    s[i] = (s[i - 1] + a[i]) % Mod;
    s2[i] = (s2[i - 1] + 1LL * a[i] * a[i] % Mod) % Mod;
    c[i] = (c[i - 1] + 1LL * i * i % Mod) % Mod;
  }
  while (q--) {
    int l, r, d;
    scanf("%d%d%d", &l, &r, &d);
    int len = r - l + 1;
    int sum = (s[r] - s[l - 1] + Mod) % Mod,
        sum2 = (s2[r] - s2[l - 1] + Mod) % Mod;
    int val = (2LL * sum * fpm(len, Mod - 2) % Mod - 1LL * (len - 1) * d % Mod +
               Mod) %
              Mod * fpm(2, Mod - 2) % Mod;
    int res = (1LL * val * val % Mod * len % Mod +
               1LL * val * (len - 1) % Mod * len % Mod * d % Mod +
               1LL * c[len - 1] * d % Mod * d % Mod) %
              Mod;
    puts(res == sum2 ? "Yes" : "No");
  }
}
