#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const double PI = acos(-1);
long long modulo(long long _a, long long _temp_mod = mod) {
  if (abs(_a) >= _temp_mod) {
    _a %= _temp_mod;
  }
  if (_a < 0) _a += _temp_mod;
  return _a;
}
long long mult(long long _a, long long _b, long long _temp_mod = mod) {
  long long _res = modulo(_a, _temp_mod) * modulo(_b, _temp_mod);
  return modulo(_res, _temp_mod);
}
long long add(long long _a, long long _b, long long _temp_mod = mod) {
  long long _res = modulo(_a, _temp_mod) + modulo(_b, _temp_mod);
  return modulo(_res, _temp_mod);
}
long long power(long long _a, long long _b, long long _temp_mod = mod) {
  if (_b < 0) return 0;
  long long _res = 1;
  while (_b) {
    if (_b & 1) _res = mult(_res, _a, _temp_mod);
    _a = mult(_a, _a, _temp_mod);
    _b >>= 1;
  }
  return _res;
}
void pre_comp(void) {}
void solve(long long _test) {
  long long n, k;
  cin >> n >> k;
  vector<long long> arr(n);
  long long ans = INT_MIN;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if (n > 100) {
    ans = n * (n - 1) - k * (arr[n - 1] | arr[n - 2]);
  } else {
    for (long long i = 1; i <= n; i++) {
      for (long long j = i + 1; j <= n; j++) {
        long long temp = i * j - k * (arr[i - 1] | arr[j - 1]);
        ans = max(ans, temp);
      }
    }
  }
  cout << ans << '\n';
}
int32_t main(void) {
  std::ios::sync_with_stdio(0);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  pre_comp();
  long long _t = 1;
  cin >> _t;
  for (long long i = 1; i <= _t; i++) {
    solve(i);
  }
  return 0;
}
