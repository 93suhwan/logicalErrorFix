#include <bits/stdc++.h>
using namespace std;
int nums[10005], n;
bool f[2005], g[2005];
bool check(int mid) {
  memset(f, 0, sizeof(f));
  memset(g, 0, sizeof(g));
  for (int i = 0; i <= mid; ++i) {
    f[i] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= 2000; ++j) {
      if (j + nums[i] <= mid) {
        g[j + nums[i]] |= f[j];
      }
      if (j - nums[i] >= 0) {
        g[j - nums[i]] |= f[j];
      }
    }
    memcpy(f, g, sizeof(g));
    memset(g, 0, sizeof(g));
  }
  for (int i = 0; i <= mid; ++i) {
    if (f[i]) {
      return true;
    }
  }
  return false;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &nums[i]);
    }
    int l = 0, r = 2000, ans;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (check(mid)) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
