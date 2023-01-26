#include <bits/stdc++.h>
using namespace std;
long long a[200000 + 1];
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    long long mpos = 0, ppos = 0;
    for (int i = 1; i <= n; i++) {
      if (a[n - i + 1] > 0) ppos = n - i + 1;
      if (a[i] < 0) mpos = i;
    }
    long long left = a[1], right = a[n];
    if (left < 0) left *= -1;
    long long sum = 0;
    if (ppos != 0) {
      long long s = ppos - 1;
      if ((n - ppos + 1) % k != 0) {
        long long r = s + (n - ppos + 1) % k;
        sum += a[r] * 2;
      }
      for (int i = s + k; i <= n; i += k) sum += a[i] * 2;
    }
    if (mpos != 0) {
      long long s = mpos + 1;
      if ((mpos) % k != 0) {
        long long r = s - (mpos % k);
        sum -= a[r] * 2;
      }
      for (long long i = s - k; i >= 1; i -= k) sum -= a[i] * 2;
    }
    if (ppos != 0 and mpos == 0)
      sum -= a[n];
    else if (ppos == 0 and mpos != 0)
      sum += a[1];
    else {
      if (left < right)
        sum -= a[n];
      else
        sum += a[1];
    }
    printf("%lld\n", sum);
  }
  return 0;
}
