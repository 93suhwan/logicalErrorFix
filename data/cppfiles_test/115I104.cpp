#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int t, n, arr[MAXN], h, sub[MAXN], cnt, add[MAXN];
bool check(int x) {
  long long res = n;
  int idx = lower_bound(sub, sub + cnt + 1, x - 1) - sub;
  res += add[idx - 1] + (x - 1) * (n - idx + 1);
  if (res >= h) return true;
  return false;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    cnt = 0;
    memset(sub, 0, sizeof(sub));
    memset(add, 0, sizeof(add));
    scanf("%d%d", &n, &h);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &arr[i]);
      if (i > 1) sub[++cnt] = arr[i] - arr[i - 1] - 1;
    }
    sort(sub + 1, sub + cnt + 1);
    for (int i = 1; i <= cnt; ++i) add[i] = add[i - 1] + sub[i];
    long long l = 1, r = h;
    while (l < r) {
      long long mid = (l + r) >> 1;
      if (check(mid))
        r = mid;
      else
        l = mid + 1;
    }
    printf("%d\n", l);
  }
}
