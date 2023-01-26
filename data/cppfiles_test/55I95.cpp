#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
const int N = 2e5;
long long exp(long long x, long long y) {
  long long ans = 1;
  x %= mod;
  while (y > 0) {
    if (y & 1) ans = (ans * x) % mod;
    y >>= 1;
    x = (x * x) % mod;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  long long pow = (1 << n) - 2;
  long long res = exp(4, pow);
  res *= 6;
  res %= mod;
  cout << res;
}
