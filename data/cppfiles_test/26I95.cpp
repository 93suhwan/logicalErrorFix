#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long Mod = 1000000007;
int main() {
  int T, n;
  long long sum;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    n *= 2;
    sum = 1;
    for (int i = n; i >= 1; i--) {
      sum *= i;
      sum %= Mod;
    }
    sum %= Mod;
    printf("%lld\n", sum / 2);
  }
  return 0;
}
