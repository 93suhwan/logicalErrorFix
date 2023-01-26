#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int modulo = 998244353;
;
const int INF = (int)1e9 + 47;
const int nax = 2 * (int)1e5 + 10;
const int lim = 2 * (int)1e3 + 10;
const double EPS = 1e-10;
const int sqrt_const = 451;
int v[nax], k[nax];
int dp[nax][sqrt_const];
int sz[nax];
int cur[nax];
vector<int> g[nax];
int ans[nax];
void small(int v, int p = -1) {
  for (auto to : g[v]) {
    if (to == p) continue;
    small(to, v);
    for (int magik = 0; magik < sqrt_const; magik++) {
      dp[v][magik] += max(dp[to][magik] - magik, 1);
    }
  }
}
void big(int v, int p = -1) {
  sz[v] = 1;
  for (int i = 0; i < sqrt_const; i++) dp[v][i] = 0;
  for (auto to : g[v]) {
    if (to == p) continue;
    big(to, v);
    for (int i = 0; i < sqrt_const; i++) cur[i] = 0;
    for (int i = 0; i < min(sz[v] + 1, sqrt_const); i++) {
      cur[i] = max(cur[i], dp[v][i] + 1);
      for (int j = 0; j <= sz[to]; j++) {
        if (i + j + 1 >= sqrt_const) break;
        cur[i + j + 1] = max(cur[i + j + 1], dp[v][i] + dp[v][j]);
      }
    }
    sz[v] += sz[to];
    for (int i = 0; i < min(sz[v] + 1, sqrt_const); i++) dp[v][i] = cur[i];
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int q;
  cin >> q;
  for (int qq = 0; qq < q; qq++) {
    cin >> v[qq] >> k[qq];
    --v[qq];
  }
  small(0, -1);
  for (int qq = 0; qq < q; qq++) {
    if (k[qq] < sqrt_const) ans[qq] = dp[v[qq]][k[qq]];
  }
  big(0, -1);
  for (int qq = 0; qq < q; qq++) {
    if (k[qq] >= sqrt_const) {
      for (int j = 0; j < sqrt_const; j++)
        ans[qq] = max(ans[qq], dp[v[qq]][j] - j * k[qq]);
    }
  }
  for (int qq = 0; qq < q; qq++) {
    cout << ans[qq] << '\n';
  }
}
