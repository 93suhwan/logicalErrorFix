#include <bits/stdc++.h>
using namespace std;
const int N = 2004 + 4;
int a[10004], mx, n;
bitset<N << 1> now, limit;
bool check(int x) {
  limit.reset();
  for (int i = 0; i <= min(x, N); i++) limit.set(i);
  now = limit;
  for (int i = 1; i <= n; i++) now = (now >> a[i]) | (now << a[i]) & limit;
  return now.any();
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d", &n);
    mx = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      mx = max(mx, a[i]);
    }
    int l = mx, r = mx << 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(mid))
        r = mid - 1;
      else
        l = mid + 1;
    }
    cout << l << endl;
  }
  return 0;
}
