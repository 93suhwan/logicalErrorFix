#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int main() {
  long long T, N, K;
  scanf("%lld", &T);
  while (T--) {
    long long ans = 0;
    scanf("%lld %lld", &N, &K);
    long long U = 1;
    while (K > 0) {
      int X = K % 2;
      K /= 2;
      if (X) ans = (ans + U) % 1000000007;
      U = (U * N) % 1000000007;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
