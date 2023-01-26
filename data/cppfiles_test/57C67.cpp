#include <bits/stdc++.h>
using namespace std;
int T;
long long s, n, k;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%lld%lld%lld", &s, &n, &k);
    long long cnt;
    if (s % k == 0) {
      if ((s / k) & 1) {
        cnt = (s / k + 1) / 2 * k;
      } else
        cnt = (s / k) / 2 * k + 1;
    } else {
      long long tmp = (s % k) + 1;
      cnt = tmp * ((s / k + 2) / 2) + (k - tmp) * ((s / k + 1) / 2);
    }
    cnt--;
    if (n > cnt || s == k)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
