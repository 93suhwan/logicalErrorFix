#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e9;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
long long quickpow(long long a, long long k) {
  long long res = 1;
  while (k) {
    if (k % 2 == 1) res *= a % mod;
    k >>= 1;
    a = a * a % mod;
  }
  return res;
}
void sol() {
  int x;
  cin >> x;
  long long x1 = (1ll << x) - 2;
  long long ans = 6 * quickpow(4ll, x1) % mod;
  cout << ans << endl;
}
int main() {
  sol();
  return 0;
}
