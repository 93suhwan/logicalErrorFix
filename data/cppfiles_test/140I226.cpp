#include <bits/stdc++.h>
using namespace std;
int T;
long long n;
long long cnt2;
long long cnt3;
long long cnt6;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%lld", &n);
    cnt2 = (long long)sqrt(n);
    while (pow(cnt3, 3) <= n + 0.2) {
      cnt3++;
    }
    cnt3--;
    while (pow(cnt6, 6) <= n + 0.2) {
      cnt6++;
    }
    cnt6--;
    printf("%lld\n", cnt2 + cnt3 - cnt6);
  }
  return 0;
}
