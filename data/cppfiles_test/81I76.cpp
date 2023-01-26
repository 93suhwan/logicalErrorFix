#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, m, d, s[500005], a[500005];
pair<pair<int, int>, int> val[500005];
int dp[500005];
int main() {
  scanf("%d%d", &n, &d);
  for (int i = 0; i < (int)(n); i++) {
    scanf("%d%d", &s[i], &a[i]);
    if (s[i] < d) continue;
    if (s[i] < a[i])
      val[m++] = make_pair(make_pair(a[i], s[i]), 0);
    else
      val[m++] = make_pair(make_pair(s[i], a[i]), 1);
  }
  sort(val, val + m);
  int mx = 0, cnt = 0;
  dp[0] = 0;
  for (int i = 0; i < (int)(m); i++) {
    mx = max(mx, val[i].first.second);
    if (i > 0) dp[i] = dp[i - 1];
    if (val[i].second) {
      cnt++;
      continue;
    }
    if (mx > val[i].first.second) continue;
    int best =
        upper_bound(val, val + m,
                    make_pair(make_pair(val[i].first.second, INF), INF)) -
        val - 1;
    if (best < 0) best = 0;
    dp[i] = max(dp[i], dp[best] + 1);
  }
  printf("%d\n", dp[m - 1] + cnt);
  return 0;
}
