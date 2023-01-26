#include <bits/stdc++.h>
using namespace std;
long long t, n;
long long qpow(long long a, long long b) {
  long long x = 1, base = a;
  while (b) {
    if (b & 1) {
      x = (x * base) % 1000000007;
    }
    base = (base * base) % 1000000007;
    b >>= 1;
  }
  return x % 1000000007;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  long long ans = (qpow(4, ((1ll << n) - 2)) * 6) % 1000000007;
  cout << ans << endl;
}
