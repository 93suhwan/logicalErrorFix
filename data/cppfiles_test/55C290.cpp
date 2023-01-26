#include <bits/stdc++.h>
using namespace std;
long long modd(long long x, long long e) {
  long long result = 1;
  x = x % 1000000007;
  while (e != 0) {
    if (e % 2 == 1) {
      result *= x;
      result = result % 1000000007;
    }
    e = e / 2;
    x = x * x;
    x = x % 1000000007;
  }
  return result;
}
void solve() {
  long long k;
  cin >> k;
  long long x = pow(2, k - 1);
  x = x % 1000000007;
  long long y = pow(2, k - 1) / 1000000007;
  x = x + y;
  x = modd(16, x - 1);
  x *= 6;
  x = x % 1000000007;
  cout << x << "\n";
}
int32_t main() {
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
}
