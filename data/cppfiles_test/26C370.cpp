#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main(void) {
  long long n, t;
  cin >> t;
  while (t--) {
    cin >> n;
    long long sum = 1;
    long long i;
    for (i = 1; i <= 2 * n; i++) {
      sum = sum * i % mod;
      if (i == 2) sum /= 2;
    }
    printf("%lld\n", sum);
  }
}
