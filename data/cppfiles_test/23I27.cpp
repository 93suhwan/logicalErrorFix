#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
template <class T>
using vi2 = vector<vector<T>>;
using ll = long long;
using pii = pair<int, int>;
int main() {
  auto solve = [&]() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), per(n + 1), fa(n + 1), sz(n + 1);
    for (int i = 1, _i = int(n); i <= _i; i++) cin >> a[i];
    function<int(int)> root = [&](int x) {
      return fa[x] ? fa[x] = root(fa[x]) : x;
    };
    auto un = [&](int a, int b) {
      a = root(a), b = root(b);
      fa[a] = b;
    };
    for (int i = 1, _i = int(n); i <= _i; i++) per[i] = i;
    sort(per.begin() + 1, per.end(), [&](int x, int y) { return a[x] > a[y]; });
    vi2<int> g(n + 1);
    for (int i = 1, _i = int(n); i <= _i; i++) {
      int x = per[i];
      if (x != 1 && a[x - 1] > a[x]) {
        int r = root(x - 1);
        g[x].emplace_back(r);
        un(r, x);
      }
      if (x != n && a[x + 1] > a[x]) {
        int r = root(x + 1);
        g[x].emplace_back(r);
        un(r, x);
      }
    }
    int r = per[n];
    vi2<ll> dp(n + 1, vector<ll>(m + 1, -LLONG_MAX / 3));
    function<void(int, int)> dfs = [&](int x, int fa) {
      vector<ll> dp1(m + 1, -LLONG_MAX / 3), dp2(m + 1, -LLONG_MAX / 3);
      dp1[0] = 0;
      dp2[1] = 1LL * (m - 1) * a[x];
      sz[x] = 0;
      vector<ll> tmp1(m + 1, -LLONG_MAX / 3), tmp2(m + 1, -LLONG_MAX / 3);
      for (int to : g[x]) {
        dfs(to, x);
        fill_n(tmp1.begin(), min(m + 1, sz[x] + sz[to] + 1), -LLONG_MAX / 3);
        fill_n(tmp2.begin(), min(m + 1, sz[x] + sz[to] + 1), -LLONG_MAX / 3);
        for (int l = 0, _l = int(min(sz[x], m)); l <= _l; l++)
          for (int r = 0, _r = int(min(sz[to], m - sz[x])); r <= _r; r++) {
            tmp1[l + r] =
                max(dp1[l] + dp[to][r] - 2LL * l * r * a[x], tmp1[l + r]);
            if (l + r + 1 <= m)
              tmp2[l + r + 1] =
                  max(dp1[l] + dp[to][r] +
                          1LL *
                              (m - 1LL * (l + r + 1) * (l + r + 1) +
                               1LL * l * l + 1LL * r * r) *
                              a[x],
                      tmp2[l + r + 1]);
          }
        sz[x] += sz[to];
        dp1 = tmp1, dp2 = tmp2;
      }
      sz[x]++;
      for (int i = 0, _i = int(m); i <= _i; i++) dp[x][i] = max(dp1[i], dp2[i]);
    };
    dfs(r, r);
    cout << dp[r][m] << endl;
  };
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
