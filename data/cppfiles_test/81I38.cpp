#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int n, d, dp[500005], t[1000005], cnt;
pair<int, pair<int, int> > p[500005];
map<int, int> m;
int q[1000005];
void upd(int x, int k) {
  while (x <= cnt) t[x] = max(t[x], k), x += (x & -x);
}
int get(int x) {
  int ret = 0;
  while (x) ret = max(ret, t[x]), x -= (x & -x);
  return ret;
}
int main() {
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= n; ++i)
    scanf("%d%d", &p[i].second.second, &p[i].second.first),
        p[i].second.first = max(p[i].second.first, d),
        p[i].first = min(p[i].second.first, p[i].second.second);
  for (int i = 1; i <= n; ++i)
    q[i] = p[i].second.first, q[n + i] = p[i].second.second;
  sort(q + 1, q + n * 2 + 1);
  q[0] = -1;
  cnt = 0;
  for (int i = 1; i <= n * 2; ++i)
    if (q[i] != q[i - 1]) m[q[i]] = ++cnt;
  sort(p + 1, p + n + 1);
  for (int i = 1; i <= n; ++i) {
    if (p[i].second.second < d) continue;
    dp[i] = get(m[p[i].second.second]) + 1;
    upd(m[p[i].second.first], dp[i]);
  }
  printf("%d\n", get(cnt));
  return 0;
}
