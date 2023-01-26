#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(false);
  int t;
  long long k, x, y;
  cin >> t;
  while (t--) {
    cin >> k;
    if (k % 3 == 0)
      printf("%lld %lld\n", k / 3, k / 3);
    else if (k % 3 == 1)
      printf("%lld %lld\n", k / 3 + 1, k / 3);
    else
      printf("%lld %lld\n", k / 3, k / 3 + 1);
  }
}
