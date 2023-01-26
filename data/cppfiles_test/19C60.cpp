#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool ckmax(T &x, const T &y) {
  return x < y ? x = y, true : false;
}
template <class T>
inline bool ckmin(T &x, const T &y) {
  return x > y ? x = y, true : false;
}
const int maxn = 1e4 + 10;
int a[maxn], m, mx, n, t_case;
bitset<maxn> bitmask, cur;
inline bool check(int k) {
  bitmask.reset(), cur.reset();
  for (register int i = 0; i <= k; ++i) bitmask[i] = cur[i] = 1;
  for (register int i = 1; i <= n; ++i) {
    cur = ((cur << a[i]) | (cur >> a[i])) & bitmask;
    if (!cur.any()) return false;
  }
  return true;
}
inline int half() {
  register int l = mx, r = mx << 1, ret = mx << 1;
  while (l <= r) {
    register int mid = l + r >> 1;
    if (check(mid))
      ret = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  return ret;
}
int main() {
  scanf("%d", &t_case);
  while (t_case--) {
    scanf("%d", &n);
    mx = 0;
    for (register int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      ckmax(mx, a[i]);
    }
    printf("%d\n", half());
  }
  return 0;
}
