#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    if (n == 0 && m == 0)
      printf("1\n");
    else if (n > m)
      printf("0\n");
    else {
      long long a[30 + 1] = {0}, idx = 0;
      long long sum = 0, val = 1, cnt = 1;
      long long nn = n;
      while (nn != 0) {
        if (nn % 2 == 0) a[++idx] = val, cnt *= 2;
        nn /= 2;
        val *= 2;
      }
      a[0] = 1;
      while (val <= m * 2) a[++idx] = val, val *= 2, cnt *= 2;
      long long low = 0, high = cnt - 1;
      long long ans = 0;
      while (low <= high) {
        long long mid = (low + high) / 2;
        long long val = mid;
        long long bits[30 + 1] = {0}, i = 0;
        while (val != 0) {
          bits[++i] = val % 2;
          val /= 2;
        }
        long long sum = 0;
        for (long long j = 1; j <= idx; j++)
          if (bits[j] == 1) sum += a[j];
        if (sum + n <= m)
          low = mid + 1;
        else
          high = mid - 1, ans = sum;
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}
