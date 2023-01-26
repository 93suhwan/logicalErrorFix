#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline", "fast-math", "unroll-loops", \
                     "no-stack-protector")
using namespace std;
long long n, dp[400010], sum[400010];
bool vis[400010], qry[400010];
vector<pair<long long, pair<long long, long long> > > vt;
struct BIT {
  long long val[400010];
  void init() {
    memset(val, 0, sizeof(val));
    return;
  }
  void upd(long long x, long long v) {
    x++;
    while (x < 400010) {
      val[x] = (val[x] + v) % 1000000007;
      x += x & (-x);
    }
    return;
  }
  long long qry(long long x) {
    x++;
    long long ret = 0;
    while (x > 0) {
      ret = (ret + val[x]) % 1000000007;
      x -= x & (-x);
    }
    return ret;
  }
} bit;
int main() {
  long long i, l, r;
  scanf("%lld", &n);
  for (i = 0; i < n; i++) {
    scanf("%lld%lld", &l, &r);
    vt.push_back(make_pair(r, make_pair(l, i)));
  }
  sort(vt.begin(), vt.end());
  scanf("%lld", &r);
  while (r--) {
    scanf("%lld", &l);
    vis[l - 1] = true;
  }
  bit.init();
  for (i = 0; i < vt.size(); i++) {
    if (vis[vt[i].second.second]) {
      qry[i] = true;
    }
  }
  for (i = 0; i < vt.size(); i++) {
    dp[i] =
        (bit.qry(2 * n + 1) + 1000000007 - bit.qry(vt[i].second.first) + 1) %
        1000000007;
    bit.upd(vt[i].second.first, dp[i]);
  }
  bit.init();
  long long ans = 0, cur = 0;
  for (i = 0; i < vt.size(); i++) {
    bit.upd(vt[i].second.first, dp[i]);
  }
  for (i = vt.size() - 1; i >= 0; i--) {
    bit.upd(vt[i].second.first, 1000000007 - dp[i]);
    if (qry[i] && vt[i].second.first > cur) {
      ans = (ans + bit.qry(2 * n + 1) + 1000000007 - bit.qry(cur) + 1) %
            1000000007;
      cur = vt[i].second.first;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
