#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005, base1 = 7, base2 = 11, mod1 = 10000019,
          mod2 = 10000079;
int n, ps, no1, no2, no3, ans, ans1, ans2, ans3, now1, now2;
int c[maxn], p[maxn], mn[maxn], mul1[maxn], mul2[maxn], rec1[maxn], rec2[maxn],
    recrec1[maxn], recrec2[maxn];
map<pair<int, int>, int> mp;
void check() {
  int res = n - (no1 != 0) - (no2 != 0);
  if (res > ans) ans = res, ans1 = no1, ans2 = no2, ans3 = no3;
}
void solve() {
  now1 = now2 = 0;
  for (int i = 2; i <= n; i += 2) now1 ^= rec1[i], now2 ^= rec2[i];
  if (n & 1)
    for (int i = 1; i <= n; i++) now1 ^= rec1[i], now2 ^= rec2[i];
  if (now1 == 0 && now2 == 0) no1 = no2 = 0, check();
  for (int i = 1; i <= n; i++) {
    now1 ^= rec1[i], now2 ^= rec2[i];
    if (now1 == 0 && now2 == 0) no1 = i, no2 = 0, check();
    if (mp.count(make_pair(now1, now2)))
      no1 = i, no2 = mp[make_pair(now1, now2)], check();
  }
}
int main() {
  scanf("%d", &n);
  c[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (c[i] == 0) p[++ps] = i, mn[i] = i;
    for (int j = 1; j <= ps && i * p[j] <= n; j++) {
      c[i * p[j]] = 1, mn[i * p[j]] = p[j];
      if (i % p[j] == 0) break;
    }
  }
  mul1[0] = mul2[0] = 1;
  for (int i = 1; i <= n; i++)
    mul1[i] = 1ll * mul1[i - 1] * base1 % mod1,
    mul2[i] = 1ll * mul2[i - 1] * base2 % mod2;
  for (int i = 1; i <= n; i++) {
    int v1 = 0, v2 = 0, k = i;
    while (k > 1) {
      int p = mn[k], c = 0;
      while (k % p == 0) k /= p, c ^= 1;
      if (c) v1 ^= mul1[p], v2 ^= mul2[p];
    }
    rec1[i] = v1, rec2[i] = v2, now1 ^= v1, now2 ^= v2,
    mp[make_pair(now1, now2)] = i, recrec1[i] = now1, recrec2[i] = now2;
  }
  solve(), no3 = n, n--, solve(), n++;
  printf("%d\n", ans);
  now1 = 0;
  for (int i = 1; i <= n; i++)
    if (i != ans1 && i != ans2 && i != ans3)
      printf("%d ", i), now1 ^= recrec1[i], now2 ^= recrec2[i];
  puts("");
  return 0;
}
