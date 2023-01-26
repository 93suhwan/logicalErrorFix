#include <bits/stdc++.h>
#pragma GCC optmize("O3,unroll-loops")
using namespace std;
const long long mod = 1e9 + 7;
inline long long inv(long long x, long long MOD = mod) {
  long long power = MOD - 2, ret = 1;
  while (power) {
    if (power & 1) (ret *= x) %= MOD;
    power >>= 1;
    (x *= x) %= MOD;
  }
  return ret;
}
inline long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
int n;
long long arr[200000 + 5];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    if (n == 1) {
      cout << 1 << '\n';
    } else {
      int left = 0, maxx = 1;
      for (int i = 1; i < n; i++) {
        long long now = abs(arr[i] - arr[i - 1]);
        while (left < i && gcd(now, abs(arr[left] - arr[left + 1])) == 1) {
          left++;
        }
        maxx = max(maxx, i - left + 1);
      }
      cout << maxx << '\n';
    }
  }
}
