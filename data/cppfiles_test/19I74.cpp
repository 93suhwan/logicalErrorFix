#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int T, n;
int a[10010];
bool check(int len) {
  for (int ed = 0; ed <= len; ++ed) {
    int nowl = ed, nowr = len - ed;
    bool flag = 0;
    for (int i = n; i >= 1; --i) {
      if (nowl < nowr) {
        if (a[i] <= nowl) {
          nowl -= a[i];
          nowr += a[i];
        } else {
          nowl += a[i];
          nowr -= a[i];
        }
      } else {
        if (a[i] <= nowr) {
          nowr -= a[i];
          nowl += a[i];
        } else {
          nowr += a[i];
          nowl -= a[i];
        }
      }
      if (nowl < 0 || nowr < 0) {
        flag = 1;
        break;
      }
    }
    if (!flag) {
      return true;
    }
  }
  return false;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int l = 1, r = 2010;
    int ans;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (check(mid)) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
