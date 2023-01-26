#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
set<int> st;
int a[N];
pair<int, int> tmp[N], b[N];
set<pair<int, int> > sti;
long long dp[N][2];
void update(long long &first, long long second) {
  if (first == -1 || first > second) first = second;
}
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  st.clear();
  sti.clear();
  for (int i = 0; i <= n + 1; i++) {
    dp[i][0] = dp[i][1] = -1;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    st.insert(a[i]);
  }
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    int first, second;
    scanf("%d%d", &first, &second);
    set<int>::iterator it = st.lower_bound(first);
    if (it != st.end() && *it <= second) continue;
    tmp[++cnt] = make_pair(first, second);
  }
  sort(tmp + 1, tmp + cnt + 1);
  for (int i = 1; i <= cnt;) {
    int j = i;
    while (j <= cnt && tmp[j].first == tmp[i].first) j++;
    while (!sti.empty() && sti.rbegin()->first >= tmp[i].second)
      sti.erase(*sti.rbegin());
    sti.insert(make_pair(tmp[i].second, i));
    i = j;
  }
  m = 0;
  for (set<pair<int, int> >::iterator it = sti.begin(); it != sti.end(); it++)
    b[++m] = tmp[it->second];
  if (m <= 0) {
    printf("0\n");
    return;
  }
  sort(a + 1, a + n + 1);
  long long ans = -1;
  if (m == 1) {
    for (int i = 1; i <= n; i++) {
      int dis = min(abs(a[i] - b[1].first), abs(a[i] - b[1].second));
      if (ans == -1 || ans > dis) ans = dis;
    }
    printf("%lld\n", ans);
    return;
  }
  if (b[1].first >= a[n]) {
    printf("%d\n", b[m].first - a[n]);
    return;
  } else if (a[1] >= b[m].second) {
    printf("%d\n", a[1] - b[1].second);
    return;
  }
  cnt = 1;
  while (cnt <= n && a[cnt] < b[1].first) cnt++;
  if (cnt == 1) {
    long long dist = a[1] - b[1].second;
    dp[1][0] = dist;
    dp[1][1] = 2 * dist;
  } else {
    dp[cnt][0] = a[cnt] - b[1].second;
    dp[cnt][1] = 2LL * (a[cnt] - b[1].second);
    for (int i = 1; i <= m; i++) {
      if (a[cnt - 1] < b[i].first && a[cnt] > b[i].second) {
        long long dist1 = b[i].first - a[cnt - 1];
        long long dist2 = 0;
        if (i + 1 <= m && a[cnt] > b[i + 1].second)
          dist2 = a[cnt] - b[i + 1].second;
        if (dist2) update(dp[cnt][0], dist1 + dist2);
        update(dp[cnt][1], dist1 + dist2 * 2);
      }
    }
  }
  int j = 1;
  while (j <= m && a[cnt] > b[j].first) j++;
  for (int i = cnt; i <= n; i++) {
    if (j > m) {
      if (dp[i][0] != -1) update(ans, dp[i][0]);
      if (dp[i][1] != -1) update(ans, dp[i][1]);
      break;
    }
    long long dist = b[m].first - a[i];
    if (dp[i][0] != -1) update(ans, dp[i][0] + 2 * dist);
    if (dp[i][1] != -1) update(ans, dp[i][1] + dist);
    if (i == n) break;
    int k = j;
    while (k <= m && a[i + 1] >= b[k].first) k++;
    if (k == j) {
      dp[i + 1][0] = dp[i][0];
      dp[i + 1][1] = dp[i][1];
      continue;
    }
    if (dp[i][0] != -1) {
      dp[i + 1][0] = dp[i][0] + (a[i + 1] - b[j].second);
      dp[i + 1][1] = dp[i][0] + 2LL * (a[i + 1] - b[j].second);
    }
    for (int r = j; r < k; r++) {
      long long dist1 = b[r].first - a[i];
      long long dist2 = 0;
      if (r + 1 < k) dist2 = a[i + 1] - b[r + 1].second;
      if (dist2) {
        if (dp[i][0] != -1) update(dp[i + 1][0], dp[i][0] + 2 * dist1 + dist2);
        if (dp[i][1] != -1) update(dp[i + 1][0], dp[i][1] + dist1 + dist2);
      }
      if (dp[i][0] != -1)
        update(dp[i + 1][1], dp[i][0] + 2 * dist1 + 2 * dist2);
      if (dp[i][1] != -1) update(dp[i + 1][1], dp[i][1] + dist1 + 2 * dist2);
    }
    j = k;
  }
  printf("%lld\n", ans);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
