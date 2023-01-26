#include <bits/stdc++.h>
long long mod = 1000000007;
using namespace std;
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    b >>= 1;
    a = (a * a) % mod;
  }
  return res;
}
bool isprime(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
void solve() {
  long long x, n;
  cin >> x >> n;
  if (n == 0) {
    cout << x << endl;
    return;
  }
  long long k = n - 1;
  long long c = k / 4;
  long long rem = k % 4;
  long long ans = x;
  if (x % 2 == 0) {
    ans -= 1;
    ans -= (c * 4);
    if (rem == 1)
      ans += n;
    else if (rem == 2)
      ans += (n + n - 1);
    else if (rem == 3)
      ans += (n - 2 + n - 1 - n);
  } else {
    ans += 1;
    ans += (c * 4);
    if (rem == 1)
      ans -= n;
    else if (rem == 2)
      ans -= (n + n - 1);
    else if (rem == 3)
      ans -= (n - 2 + n - 1 - n);
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
