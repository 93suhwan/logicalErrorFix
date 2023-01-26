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
    sort(cnt + 1, cnt + flag + 1, cmp);
    int now = cnt[1];
    for (int i = 2; i <= flag; i++) now = abs(now - cnt[i]);
    printf("%d\n", now / 2 + ans);
  }
  return 0;
}
