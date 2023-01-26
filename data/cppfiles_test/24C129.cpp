#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
const double eps = 1e-12;
const double PI = acos(-1.0);
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
const long long nax = 5e5 + 5;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool isPowerOfTwo(long long int x) { return x && (!(x & (x - 1))); }
void solve() {
  long long int i, n, ans, k, m, j;
  cin >> n;
  if (n % 10 == 9) {
    ans = 1;
    n /= 10;
    n += 1;
    cout << n << "\n";
  } else {
    cout << n / 10 << "\n";
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int t = 1, i;
  cin >> t;
  while (t--) solve();
  return 0;
}
