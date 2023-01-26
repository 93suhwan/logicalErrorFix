#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long binpow_mod(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInv(long long a) {
  return binpow_mod(a, 1000000007 - 2, 1000000007);
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
void solve() {
  int n;
  cin >> n;
  long long ans = 0;
  long long temp;
  for (long long i = 0; i < n; i++) {
    cin >> temp;
    if (temp - i - 1 > ans) {
      ans = temp - i - 1;
    }
  }
  cout << ans << endl;
}
int main() {
  fast();
  int test_cases = 1;
  cin >> test_cases;
  for (int T = 0; T < test_cases; T++) {
    solve();
  }
}
