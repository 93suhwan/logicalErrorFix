#include <bits/stdc++.h>
using namespace std;
static constexpr int Maxn = 1e6 + 5;
int n, m;
int a[Maxn], b[Maxn], buf[Maxn];
int64_t calc(int l, int r) {
  if (l == r) return 0;
  int mid = (l + r) >> 1;
  int64_t ans = calc(l, mid) + calc(mid + 1, r);
  for (int s = 0, i = l, j = mid + 1; s < r - l + 1;) {
    if (i <= mid && (j == r + 1 || a[i] <= a[j]))
      ans += j - (mid + 1), buf[s++] = a[i++];
    else
      buf[s++] = a[j++];
  }
  for (int i = l; i <= r; ++i) a[i] = buf[i - l];
  return ans;
}
int main(void) {
  int tests;
  scanf("%d", &tests);
  while (tests--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i) scanf("%d", &b[i]);
    sort(b + 1, b + m + 1);
    priority_queue<int> pq;
    pq.push(0);
    int64_t ans = 0;
    for (int i = 1; i <= n; ++i) {
      int l = lower_bound(b + 1, b + m + 1, a[i]) - b;
      int r = upper_bound(b + 1, b + m + 1, a[i]) - b;
      pq.push(l);
      if (pq.top() > r) {
        ans += pq.top() - r;
        pq.pop();
        pq.push(r);
      }
    }
    ans += calc(1, n);
    printf("%lld\n", ans);
  }
  exit(EXIT_SUCCESS);
}
