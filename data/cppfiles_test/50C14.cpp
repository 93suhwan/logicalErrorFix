#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long n, a[200010], dp[200010][2];
pair<long long, long long> res = make_pair(0, 0);
stack<long long> stk;
namespace st {
long long n2 = 1, dat[800010][2];
void upd(long long k, pair<long long, long long> val) {
  dat[k][0] = val.first;
  dat[k][1] = val.second;
  while (k > 0) {
    k = (k - 1) / 2;
    for (int i = 0; i < 2; ++i)
      dat[k][i] = (dat[k + k + 1][i] + dat[k + k + 2][i]) % MOD;
  }
}
pair<long long, long long> qry(long long k, long long lb, long long ub,
                               long long tlb, long long tub) {
  if (ub < tlb || tub < lb) return make_pair(0, 0);
  if (tlb <= lb && ub <= tub) return make_pair(dat[k][0], dat[k][1]);
  pair<long long, long long> ret = qry(k + k + 1, lb, (lb + ub) / 2, tlb, tub),
                             ret2 = qry(k + k + 2, (lb + ub) / 2 + 1, ub, tlb,
                                        tub);
  return make_pair((ret.first + ret2.first) % MOD,
                   (ret.second + ret2.second) % MOD);
}
}  // namespace st
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
  while (st::n2 < n) st::n2 *= 2;
  long long mn = 1e18;
  for (int i = 0; i < n; ++i) {
    mn = min(mn, a[i]);
    dp[i][1] = mn;
  }
  st::upd(0 + st::n2 - 1, make_pair(dp[0][0], dp[0][1]));
  stk.push(0);
  for (int i = 1; i <= n - 1; ++i) {
    while (!stk.empty() && a[i] <= a[stk.top()]) {
      int lst = stk.top();
      stk.pop();
      int fr = (stk.empty() ? 0 : stk.top());
      pair<long long, long long> val = st::qry(0, 0, st::n2 - 1, fr, lst - 1);
      (res.first += MOD - val.first * a[lst] % MOD) %= MOD;
      (res.second += MOD - val.second * a[lst] % MOD) %= MOD;
    }
    int fr = (stk.empty() ? 0 : stk.top());
    pair<long long, long long> val = st::qry(0, 0, st::n2 - 1, fr, i - 1);
    (res.first += val.first * a[i]) %= MOD;
    (res.second += val.second * a[i]) %= MOD;
    stk.push(i);
    (dp[i][0] += res.second) %= MOD;
    (dp[i][1] += res.first) %= MOD;
    st::upd(i + st::n2 - 1, make_pair(dp[i][0], dp[i][1]));
  }
  cout << (dp[n - 1][n % 2] - dp[n - 1][(n % 2) ^ 1] + MOD) % MOD << endl;
  return 0;
}
