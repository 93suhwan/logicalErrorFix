#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
long long t, n, arr[MAXN], h, sub[MAXN], cnt, add[MAXN];
long long find(int x) {
  long long l = 0, r = cnt + 1;
  while (l < r) {
    long long mid = (l + r) >> 1;
    if (sub[mid] >= x)
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}
bool check(long long x) {
  long long res = n;
  long long idx = find(x - 1);
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
    scanf("%d%lld", &n, &h);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &arr[i]);
      if (i > 1) sub[++cnt] = arr[i] - arr[i - 1] - 1;
    }
    sort(sub + 1, sub + cnt + 1);
    for (int i = 1; i <= cnt; ++i) add[i] = add[i - 1] + sub[i];
    long long l = 1, r = 1e18;
    while (l < r) {
      long long mid = (l + r) >> 1;
      if (check(mid))
        r = mid;
      else
        l = mid + 1;
    }
    printf("%lld\n", l);
  }
}
