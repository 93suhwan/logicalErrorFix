#include <bits/stdc++.h>
#pragma GCC optimize("03")
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;
bool isPerfectSquare(long double x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
long long bigmod(long long a, int p) {
  if (p == 0) return 1;
  if (p & 1) {
    return ((a) * (bigmod(a, p - 1)));
  } else {
    long long tmp = bigmod(a, p / 2);
    return (tmp * tmp);
  }
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int ans = 0;
    for (int i = 0; i <= 32591; i++) {
      if (bigmod(i, 2) <= n || bigmod(i, 3) <= n) ans++;
    }
    cout << ans;
    cout << endl;
  }
  return 0;
}
