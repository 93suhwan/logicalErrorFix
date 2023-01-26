#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
long long T, n, m, ans;
long long l[400005], r[400005], a[400005], dp[2][400005];
struct node {
  long long l, r;
  bool operator<(const node &nd) const {
    if (l == nd.l) return r < nd.r;
    return l < nd.l;
  }
};
node mknd(long long lll, long long rr) {
  node ret;
  ret.l = lll;
  ret.r = rr;
  return ret;
}
vector<node> vec[400005];
int main() {
  ios::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> n >> m;
    n += 2;
    for (long long i = 2; i <= n - 1; i++) cin >> a[i];
    a[1] = -INF;
    a[n] = INF;
    sort(a + 1, a + 1 + n);
    for (long long i = 0; i <= n; i++) {
      l[i] = r[i] = a[i];
      vec[i].clear();
    }
    for (long long tl, tr, pl, pr, i = 1; i <= m; i++) {
      cin >> tl >> tr;
      pl = lower_bound(a + 1, a + 1 + n, tl) - a;
      pr = upper_bound(a + 1, a + 1 + n, tr) - a - 1;
      if (pl <= pr) continue;
      l[pl] = min(l[pl], tr);
      r[pr] = max(r[pr], tl);
      vec[pr].push_back(mknd(tl, tr));
    }
    for (long long i = 1; i <= n; i++) sort(vec[i].begin(), vec[i].end());
    dp[0][0] = dp[1][0] = 0;
    for (long long i = 1; i < n; i++) {
      dp[0][i] = dp[1][i] = INF;
      for (long long pre = 0; pre < 2; pre++) {
        for (long long now = 0; now < 2; now++) {
          long long val = INF, mx = a[i + 1];
          if (!vec[i].size())
            val = 0;
          else {
            for (long long j = (long long)(vec[i].size()) - 1; j >= 0; j--) {
              val = min(val, (2 - pre) * (vec[i][j].l - a[i]) +
                                 (now + 1) * (a[i + 1] - mx));
              mx = min(mx, vec[i][j].r);
            }
          }
          val = min(val, 0ll + (now + 1) * (a[i + 1] - mx));
          dp[now][i] = min(dp[now][i], dp[pre][i - 1] + val);
        }
      }
    }
    ans = min(dp[0][n - 1], dp[1][n - 1]);
    cout << ans << '\n';
  }
  return 0;
}
