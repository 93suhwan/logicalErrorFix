#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const char $ = '$';
long long temp = 0;
const long long mod = 1e9 + 7;
void solve() {
  long long k;
  cin >> k;
  long long ans = 6;
  long long pow = 1;
  for (long long i = 0; i < k; i++) {
    pow *= 2;
    pow %= (mod - 1);
  }
  long long a = pow - 2;
  for (long long i = 0; i < a / 10; i++) {
    ans *= 1048576;
    ans %= mod;
  }
  for (long long i = 0; i < a % 10; i++) {
    ans *= 4;
    ans %= mod;
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
