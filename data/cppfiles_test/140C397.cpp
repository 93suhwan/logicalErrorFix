#include <bits/stdc++.h>
using namespace std;
int T;
long long n;
long long cnt2;
long long cnt3 = 0;
long long cnt6 = 0;
long long qpow(long long a, long long b) {
  if (b == 0) return 1;
  long long ans = qpow(a, b / 2);
  if ((b & 1))
    return ans * ans * a;
  else
    return ans * ans;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%lld", &n);
    cnt2 = cnt3 = cnt6 = 0;
    cnt2 = (long long)sqrt(n);
    while (qpow(cnt3, 3) <= n) {
      cnt3++;
    }
    cnt3--;
    while (qpow(cnt6, 6) <= n) {
      cnt6++;
    }
    cnt6--;
    printf("%lld\n", cnt2 + cnt3 - cnt6);
  }
  return 0;
}
