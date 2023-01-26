#include <bits/stdc++.h>
using namespace std;
int t, n, k, a[103], b[103], cnt[103];
bool cmp(int a, int b) { return a > b; }
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    int ans = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1, cmp);
    for (int i = 2 * k + 1; i <= n; i++) ans += a[i];
    memcpy(b, a, sizeof(b));
    int flag = unique(b + 1, b + 2 * k + 1) - b - 1;
    sort(b + 1, b + flag + 1);
    for (int i = 1; i <= 2 * k; i++)
      cnt[lower_bound(b + 1, b + flag + 1, a[i]) - b]++;
    priority_queue<int> q;
    for (int i = 1; i <= flag; i++) q.push(cnt[i]);
    while (!q.empty()) {
      if (q.size() == 1) {
        ans += q.top() / 2;
        break;
      }
      int ta = q.top();
      q.pop();
      int tb = q.top();
      q.pop();
      if (ta > 1) q.push(ta - 1);
      if (tb > 1) q.push(tb - 1);
    }
    printf("%d\n", ans);
  }
  return 0;
}
