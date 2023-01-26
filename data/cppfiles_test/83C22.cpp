#include <bits/stdc++.h>
using namespace std;
const long long mod1 = 998244353;
const long long mod2 = 1e9 + 7;
long long ans;
long long n;
long long cnt1;
vector<long long> val[7];
long long sum[7];
void dfs1(long long k1, long long k2) {
  if (k1 == 7) return;
  val[k1].push_back((cnt1 - k2 + mod1) % mod1);
  sum[k1] += (cnt1 - k2 + mod1) % mod1;
  cnt1++;
  for (long long i = 0; i <= 9; ++i) {
    dfs1(k1 + 1, k2 * 10 + i);
  }
}
bool check(long long x) {
  const long long half = 1000000;
  return x * half + 999999 <= n && x * half * 10 > n;
}
long long cnt2;
long long poww[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};
void dfs2(long long k1, long long k2) {
  if (k2 > n) return;
  if (check(k2)) {
    for (long long i = 0; i <= 6; ++i) {
      long long offset = ((cnt2 + 1 - (k2 * poww[i])) % mod1 + mod1) % mod1;
      long long pos = lower_bound(val[i].begin(), val[i].end(), mod1 - offset) -
                      val[i].begin();
      (ans += (sum[i] + offset * val[i].size() -
               mod1 * (val[i].size() - pos))) %= mod2;
    }
    cnt2 += cnt1;
  } else {
    cnt2++;
    (ans += ((cnt2 - k2) % mod1 + mod1) % mod1) %= mod2;
    for (long long i = (!k1); i <= 9; ++i) {
      dfs2(k1 + 1, k2 * 10 + i);
    }
  }
}
signed main() {
  scanf("%lld", &n);
  dfs1(0, 0);
  for (long long i = 0; i <= 6; ++i) sort(val[i].begin(), val[i].end());
  cnt2 = -1;
  dfs2(0, 0);
  printf("%lld\n", ans);
}
