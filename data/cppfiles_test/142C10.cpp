#include <bits/stdc++.h>
using namespace std;
int T, n, m, cnt[100005], can[100005];
vector<int> p[100005];
bool Check(int mid) {
  for (int i = 1; i <= n; i++) cnt[i] = 0;
  for (int i = 0; i < m; i++) can[i] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < m; j++) {
      if (p[i][j] >= mid) cnt[i]++, can[j] = 1;
    }
  for (int j = 0; j < m; j++) {
    if (!can[j]) return false;
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i] >= 2) return true;
  }
  return false;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    int x, l = 0, r = -1e9;
    for (int i = 1; i <= n; i++) {
      p[i].clear();
      for (int j = 1; j <= m; j++) {
        scanf("%d", &x);
        p[i].push_back(x);
        r = max(r, x);
      }
    }
    int ans = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (Check(mid))
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
