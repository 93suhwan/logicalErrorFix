#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
const int MOD = 1e9 + 7;
const int B = 1000000;
int xmod(long long d) {
  int ret = d % P;
  return ret < 0 ? ret + P : ret;
}
long long n, cnt;
int ans;
vector<int> hv[7];
long long sum[7];
void dfs0(int dep, long long val) {
  cnt++;
  hv[dep].push_back(xmod(cnt - val));
  if (dep == 6) return;
  for (int i = 0; i < (int)(10); i++) dfs0(dep + 1, val * 10 + i);
}
int calc(int id, int coef) {
  int pos =
      lower_bound(hv[id].begin(), hv[id].end(), P - coef) - hv[id].begin();
  return (1LL * coef * (int)hv[id].size() + sum[id] -
          1LL * P * ((int)hv[id].size() - pos)) %
         MOD;
}
void dfs1(int dep, long long val) {
  if (val > n) return;
  if (dep >= 1) {
    if (val * B > n / 10 && val * B + B - 1 <= n) {
      int tmp = 1;
      for (int i = 0; i < (int)(7); i++) {
        ans = (ans + calc(i, xmod(cnt - val * tmp))) % MOD;
        tmp *= 10;
      }
      for (int i = 0; i < (int)(7); i++) cnt += hv[i].size();
      return;
    }
    cnt++;
    ans = (ans + xmod(cnt - val)) % MOD;
  }
  for (int i = !dep; i < 10; i++) dfs1(dep + 1, val * 10 + i);
}
int main() {
  scanf("%lld", &n);
  dfs0(0, 0);
  for (int i = 0; i < (int)(7); i++) {
    sort(hv[i].begin(), hv[i].end());
    for (int j = 0; j < (int)(hv[i].size()); j++) sum[i] += hv[i][j];
  }
  cnt = 0;
  dfs1(0, 0);
  printf("%d\n", ans);
  return 0;
}
