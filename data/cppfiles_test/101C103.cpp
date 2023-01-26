#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353, N = 2e5 + 5;
long long solve() {
  long long n, m, k, ans = 0;
  cin >> n >> m >> k;
  vector<long long> ax(n), ay(m);
  vector<array<long long, 2>> pnts(k);
  for (long long &x : ax) cin >> x;
  for (long long &y : ay) cin >> y;
  for (long long i = 0; i < k; i++) {
    long long x, y;
    cin >> x >> y;
    pnts[i] = {x, y};
  }
  auto cmpy = [&](array<long long, 2> &a, array<long long, 2> &b) {
    return a[1] < b[1];
  };
  auto cmpx = [&](array<long long, 2> &a, array<long long, 2> &b) {
    return a[0] < b[0];
  };
  sort(pnts.begin(), pnts.end(), cmpy);
  for (long long j = 1, i = 0; j < m; j++) {
    while (i < k and pnts[i][1] == ay[j - 1]) i++;
    map<long long, long long> cntx;
    long long totcnt = 0;
    while (i < k and pnts[i][1] < ay[j]) cntx[pnts[i][0]]++, totcnt++, i++;
    for (auto &x : cntx) ans += (totcnt - x.second) * x.second;
  }
  sort(pnts.begin(), pnts.end(), cmpx);
  for (long long j = 1, i = 0; j < n; j++) {
    while (i < k and pnts[i][0] == ax[j - 1]) i++;
    map<long long, long long> cnty;
    long long totcnt = 0;
    while (i < k and pnts[i][0] < ax[j]) cnty[pnts[i][1]]++, totcnt++, i++;
    for (auto &x : cnty) ans += (totcnt - x.second) * x.second;
  }
  assert(ans % 2 == 0);
  return ans / 2;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long T = 1;
  cin >> T;
  for (long long i = 1; i <= T; i++) {
    cout << solve() << '\n';
  }
}
