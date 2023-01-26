#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, inf = 0x3f3f3f3f;
int T;
int n, m;
vector<int> a[N];
int cnt[N];
bool check(int mid) {
  for (int i = 1; i <= m; i++) cnt[i] = 0;
  for (int i = 1; i <= m; i++)
    for (int j = 0; j < n; j++)
      if (a[i][j] >= mid) cnt[i]++;
  for (int i = 1; i <= m; i++)
    if (cnt[i] >= 2) return true;
  return false;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++) a[i].clear();
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++) {
        int x;
        scanf("%d", &x);
        a[i].push_back(x);
      }
    if (m <= n - 1) {
      int ans = inf;
      for (int i = 0; i < n; i++) {
        int maxn = 0;
        for (int j = 1; j <= m; j++) maxn = max(maxn, a[j][i]);
        ans = min(ans, maxn);
      }
      printf("%d\n", ans);
    } else {
      int l = 1, r = 1e9;
      while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid))
          l = mid;
        else
          r = mid - 1;
      }
      printf("%d\n", l);
    }
  }
  return 0;
}
