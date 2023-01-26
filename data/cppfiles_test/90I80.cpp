#include <bits/stdc++.h>
using namespace std;
const int N = (int)6e5 + 50;
const long long INF = (long long)1e18;
struct Seg {
  int l, r;
};
int n, m;
int a[N];
vector<Seg> segs[N];
long long dp[N][2];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    a[n + 1] = (int)(1e9 + 5);
    for (int i = 1; i < (n + 1); ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 0; i < (n + 1); ++i) segs[i].clear();
    for (int i = 1; i < (m + 1); ++i) {
      int l, r;
      cin >> l >> r;
      int li = lower_bound(a + 1, a + n + 2, l) - a;
      int ri = lower_bound(a + 1, a + n + 2, r) - a;
      if (a[li] == l || a[ri] == r || li != ri) continue;
      segs[li - 1].push_back({l, r});
    }
    int mx = a[n];
    for (auto p : segs[n]) mx = max(mx, p.l);
    dp[n][0] = (mx - a[n]), dp[n][1] = (mx - a[n]) * 2;
    for (int i = n - 1; i >= 1; i--) {
      multiset<int> S;
      sort(begin(segs[i]), end(segs[i]),
           [](const Seg &s1, const Seg &s2) { return s1.l < s2.l; });
      for (auto &p : segs[i]) S.insert(p.r);
      dp[i][0] = dp[i][1] = INF;
      int curmx = a[i];
      for (int j = -1; j < (int)(segs[i]).size(); j++) {
        if (j >= 0) {
          auto &p = segs[i][j];
          curmx = max(curmx, p.l);
          S.erase(S.find(p.r));
        }
        int mn = S.empty() ? a[i + 1] : *S.begin();
        dp[i][0] = min({
            dp[i][0],
            (a[i + 1] - mn) * 2 + dp[i + 1][0] + (curmx - a[i]),
            (a[i + 1] - mn) + dp[i + 1][1] + (curmx - a[i]),
        });
        dp[i][1] = min({
            dp[i][1],
            (a[i + 1] - mn) * 2 + dp[i + 1][0] + (curmx - a[i]) * 2,
            (a[i + 1] - mn) + dp[i + 1][1] + (curmx - a[i]) * 2,
        });
      }
    }
    long long res = INF;
    int mn = a[1];
    for (auto p : segs[0]) mn = min(mn, p.r);
    res = min(dp[1][0] + 2 * (a[1] - mn), dp[1][1] + 2 * (a[1] - mn));
    cout << res << '\n';
  }
}
