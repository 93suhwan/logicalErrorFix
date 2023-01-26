#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = (0); i <= (n - 1); ++i) scanf("%d", &a[i]);
    int l = 0, r = 1e9, ans = 0;
    auto check = [&](int mid) -> int {
      auto b(a);
      for (int i = (n - 1); i >= (2); --i) {
        if (b[i] < mid) return 0;
        int t = min((b[i] - mid) / 3, a[i] / 3);
        b[i - 1] += t;
        b[i - 2] += t * 2;
        b[i] -= t * 3;
      }
      return b[0] >= mid && b[1] >= mid;
    };
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (check(mid))
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
