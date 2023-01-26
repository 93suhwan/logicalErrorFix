#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007, MOD = 998244353, maxk = 7, base = 1000000;
long long n, ord;
int ans;
int sum[maxk];
vector<int> v[maxk];
void dfs1(int x, int len) {
  ord++, v[len].push_back(((ord - x) % MOD + MOD) % MOD),
      sum[len] = (sum[len] + v[len].back()) % mod;
  if (len == 6) return;
  for (int i = 0; i <= 9; i++) dfs1(x * 10 + i, len + 1);
}
void dfs2(long long x) {
  if (x > n) return;
  if (x * base + base - 1 <= n && x * base * 10 > n) {
    long long now = ord;
    for (int i = 0, mul = 1; i <= 6; i++, mul *= 10) {
      int sz = v[i].size(), dif = ((now - x * mul) % MOD + MOD) % MOD,
          pos = lower_bound(v[i].begin(), v[i].end(), MOD - dif) - v[i].begin();
      ans = (ans + 1ll * dif * sz + sum[i]) % mod,
      ans = (ans - 1ll * MOD * (sz - pos) % mod + mod) % mod;
      ord += sz;
    }
    return;
  }
  ord++, ans = (ans + ((ord - x) % MOD + MOD) % MOD) % mod;
  for (int i = 0; i <= 9; i++) dfs2(x * 10 + i);
}
int main() {
  scanf("%lld", &n);
  ord = 0, dfs1(0, 0);
  for (int i = 0; i <= 6; i++) sort(v[i].begin(), v[i].end());
  ord = 0;
  for (int i = 1; i <= 9; i++) dfs2(i);
  printf("%d\n", ans);
  return 0;
}
