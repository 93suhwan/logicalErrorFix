#include <bits/stdc++.h>
using namespace std;
long long power(long long base, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2)
      res *= base, n--;
    else
      base *= base, n /= 2;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long test;
  cin >> test;
  while (test--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) cin >> v[i];
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      long long f = 0;
      for (long long j = 0; j < n - 1; j++) {
        if (v[j] % v[i] == 0 && v[j + 1] % v[i] != 0) continue;
        if (v[j] % v[i] != 0 && v[j + 1] % v[i] == 0) continue;
        f = 1;
        break;
      }
      if (f == 0) {
        ans = v[i];
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
