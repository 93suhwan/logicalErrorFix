#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005, base = 3, mod = 1777771;
int n, ps, no1, no2, no3, now, ans, ans1, ans2, ans3;
int c[maxn], p[maxn], mn[maxn], mul[maxn], rec[maxn];
map<int, int> mp;
void check() {
  int res = n - (no1 != 0) - (no2 != 0);
  if (res > ans) ans = res, ans1 = no1, ans2 = no2, ans3 = no3;
}
void solve() {
  now = 0;
  for (int i = 2; i <= n; i += 2) now ^= rec[i];
  if (n & 1)
    for (int i = 1; i <= n; i++) now ^= rec[i];
  if (now == 0) no1 = no2 = 0, check();
  for (int i = 1; i <= n; i++) {
    now ^= rec[i];
    if (now == 0) no1 = i, no2 = 0, check();
    if (mp.count(now)) no1 = i, no2 = mp[now], check();
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
  mul[0] = 1;
  for (int i = 1; i <= n; i++) mul[i] = 1ll * mul[i - 1] * base % mod;
  for (int i = 1; i <= n; i++) {
    int v = 0, k = i;
    while (k > 1) {
      int p = mn[k], c = 0;
      while (k % p == 0) k /= p, c ^= 1;
      if (c) v ^= mul[p];
    }
    rec[i] = v, now ^= v, mp[now] = i;
  }
  solve(), no3 = n, n--, solve(), n++;
  printf("%d\n", ans);
  now = 0;
  for (int i = 1; i <= n; i++)
    if (i != ans1 && i != ans2 && i != ans3) printf("%d ", i);
  puts("");
  return 0;
}
