#include <bits/stdc++.h>
using namespace std;
inline int rd() {
  int x = 0;
  char ch, t = 0;
  while (!isdigit(ch = getchar())) t |= ch == '-';
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return x = t ? -x : x;
}
inline long long maxll(long long x, long long y) { return x > y ? x : y; }
inline long long minll(long long x, long long y) { return x < y ? x : y; }
inline long long absll(long long x) { return x > 0ll ? x : -x; }
inline long long gcd(long long x, long long y) {
  return (y == 0) ? x : gcd(y, x % y);
}
int n, ans;
int minn[200005];
pair<int, int> a[200005];
int main() {
  n = rd();
  for (int i = 1; i <= n; i++) a[i] = pair<int, int>(rd(), -i);
  sort(a + 1, a + n + 1);
  for (int i = 1, pos, x; i <= n; i++) {
    x = -a[i].second - a[i].first;
    if (x < 0) continue;
    pos = upper_bound(minn + 1, minn + ans + 1, x) - minn;
    minn[pos] = x, ans = max(ans, pos);
  }
  printf("%d\n", ans);
  return 0;
}
