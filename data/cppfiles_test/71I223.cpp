#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 1;
int n, k;
pair<int, int> a[MAXN];
long double dist(pair<int, int> A, pair<int, int> B) {
  long double d1, d2;
  d1 = A.first - B.first;
  d2 = A.second - B.second;
  return sqrt(d1 * d1 + d2 * d2);
}
long double dp[MAXN][3];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i].first, &a[i].second);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int p = 0;
  while (true) {
    int x, y;
    x = rng() % n + 1;
    y = rng() % n + 1;
    if (x != y) {
      vector<int> tmp;
      for (int i = 1; i <= n; ++i)
        if (i != y && i != x) {
          if (1ll * (a[i].second - a[y].second) * (a[i].first - a[x].first) ==
              1ll * (a[i].second - a[x].second) * (a[i].first - a[y].first))
            ;
          else
            tmp.push_back(i);
        }
      if (tmp.size() == 1) {
        p = tmp[0];
        break;
      }
    }
  }
  vector<pair<int, int> > ano;
  for (int i = 1; i <= n; ++i)
    if (i != p) ano.push_back(a[i]);
  sort(ano.begin(), ano.end());
  if (k == p) {
    if (19142 == p) cout << "!" << endl;
    long double ans = 1e18;
    long double dis = dist(ano[0], ano.back());
    for (int i = 1; i <= n; ++i)
      if (i != p)
        ans = min(ans, dis + dist(a[i], a[p]) +
                           min(dist(a[i], ano[0]), dist(a[i], ano.back())));
    printf("%.10Lf\n", ans);
  } else {
    ano.clear();
    for (int i = 1; i <= n; ++i)
      if (i != p && i != k) ano.push_back(a[i]);
    sort(ano.begin(), ano.end());
    dp[0][1] = dist(ano[0], a[p]);
    dp[0][0] = 0;
    dp[0][2] = dist(ano[0], a[p]);
    for (int i = 0; i < ano.size() - 1; ++i) {
      dp[i + 1][0] = dp[i + 1][1] = dp[i + 1][2] = 1e18;
      dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + dist(ano[i], ano[i + 1]));
      dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + dist(ano[i], ano[i + 1]) +
                                           dist(ano[i + 1], a[p]));
      dp[i + 1][2] = min(dp[i + 1][2], dp[i][2] + dist(ano[i], ano[i + 1]));
      dp[i + 1][2] = min(dp[i + 1][2], dp[i][1] + dist(ano[i + 1], a[p]));
    }
    long double ans = min(dp[ano.size() - 1][2], dp[ano.size() - 1][1]);
    ans += min(dist(a[k], ano[0]), dist(a[k], ano.back()));
    for (int i = 1; i <= n; ++i)
      if (i != p && i != k)
        ans = min(ans, dist(a[k], a[p]) + dist(ano[0], ano.back()) +
                           min(dist(a[p], ano[0]), dist(a[p], ano.back())));
    printf("%.10Lf\n", ans);
  }
  return 0;
}
