#include <bits/stdc++.h>
using namespace std;
int a[105], b[105], oth[205], f[205], vis[205];
int main() {
  int T = 1;
  cin >> T;
  while (T--) {
    int n, k, ans = 0;
    cin >> n >> k;
    int r = n - k;
    ans += r * (r - 1) / 2;
    for (int i = 1; i <= n * 2; i++) f[i] = 0;
    for (int i = 1; i <= k; i++)
      scanf("%d%d", &a[i], &b[i]), oth[a[i]] = b[i], oth[b[i]] = a[i],
                                   f[a[i]] = f[b[i]] = 1;
    for (int i = 1; i <= k; i++)
      for (int j = i + 1; j <= k; j++) {
        if (a[i] > b[i]) swap(a[i], b[i]);
        if (a[j] > b[j]) swap(a[j], b[j]);
        if (a[i] < a[j] && b[i] > a[j] && b[i] < b[j] ||
            a[i] < b[j] && b[i] > b[j] && a[i] > a[j])
          ans++;
      }
    for (int i = 1; i <= k; i++) {
      int cnt1 = 0, cnt2 = 0;
      for (int j = a[i]; j <= b[i]; j++)
        if (f[j] == 0) cnt1++;
      for (int j = b[i]; j != a[i]; j++) {
        if (j > n * 2) j -= n * 2;
        if (j == a[i]) break;
        if (f[j] == 0) cnt2++;
      }
      ans += min(cnt1, cnt2);
    }
    printf("%d\n", ans);
  }
  return 0;
}
