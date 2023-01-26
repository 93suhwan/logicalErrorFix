#include <bits/stdc++.h>
using namespace std;
const long long dim = 200009, mod = 998244353;
long long n, a[dim];
long long b[dim];
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  b[1] = a[1];
  for (long long i = 2; i <= n; i++) {
    if (b[i] >= b[i - 1]) {
      b[i] = mod + (b[i - 1] * a[i]) % mod - b[i - 1];
      b[i] %= mod;
    } else {
      b[i] = mod + (b[i - 1] * a[i]) % mod - a[i];
      b[i] %= mod;
    }
  }
  cout << b[n];
}
