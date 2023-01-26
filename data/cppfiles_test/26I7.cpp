#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int T, n;
int main() {
  scanf("%d", &T);
  while (T--) {
    long long res = 1;
    scanf("%d", &n);
    if (n == 1 || n == 2)
      printf("1\n");
    else {
      for (int i = 3; i <= 2 * n; i++) res = (long long)res * i % mod;
      printf("%lld\n", res);
    }
  }
  return 0;
}
