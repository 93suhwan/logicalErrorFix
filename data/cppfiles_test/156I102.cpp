#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, MAX = 1e9;
int n;
long long sum[N];
inline long long min(long long x, long long y) { return x < y ? x : y; }
inline int Check(int now) { return sum[n] - sum[now - 1]; }
int bs(long long x, long long minn) {
  if (x <= 0) return 0;
  int l = 2, r = n;
  while ((r - l) > 1) {
    int mid = (l + r) >> 1;
    if (sum[n] - sum[mid - 1] - minn * ((long long)n - mid + 1) >= x)
      l = mid;
    else
      r = mid;
  }
  if (sum[n] - sum[l] - minn * ((long long)n - l) >= x) l += 1;
  return n - l + 1;
}
inline void work() {
  long long now = 0LL, k;
  int minn = 0;
  scanf("%d%lld", &n, &k);
  vector<long long> a(n + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    sum[i] = sum[i - 1] + a[i];
    now += a[i];
  }
  if (now <= k) {
    printf("0\n");
    return;
  } else if (n == 1) {
    printf("%d\n", now - k);
    return;
  }
  sort(a.begin(), a.end());
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  int ans = bs(now - k, a[1]);
  for (int i = 1; i <= n; i++) {
    ans = min(ans, bs(now - k - (long long)i, a[1] - (long long)i) + i);
    if (now - k - (long long)i <= 0) break;
  }
  printf("%d\n", ans);
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) work();
  return 0;
}
