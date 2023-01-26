#include <bits/stdc++.h>
using namespace std;
long long a[100007];
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    if (n > m) {
      printf("0\n");
    } else {
      m++;
      long long ans = 0;
      for (long long i = 30; i >= 0; i--) {
        if (((1ll << i) & n) == 0 && ((1ll << i) & m) != 0) {
          ans += (1ll << i);
        } else if (((1ll << i) & n) != 0 && ((1ll << i) & m) == 0) {
          break;
        }
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}
