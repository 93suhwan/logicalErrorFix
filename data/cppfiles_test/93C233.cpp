#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
long long mod = 1000000007LL;
long long mod2 = 998244353LL;
int t, m, h;
long long k, n;
int q;
string s;
int main() {
  cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%lld%lld", &n, &k);
    if (n == 1) {
      puts("0");
    } else {
      long long i;
      long long tot = n;
      for (i = 1; i <= 60; ++i) {
        if ((1LL << (i - 1)) > k) {
          break;
        }
        tot = (1LL << i);
        if (tot >= n) break;
      }
      if (tot >= n) {
        printf("%lld\n", i);
      } else {
        i--;
        i += (n - tot + k - 1) / k;
        printf("%lld\n", i);
      }
    }
  }
  return 0;
}
