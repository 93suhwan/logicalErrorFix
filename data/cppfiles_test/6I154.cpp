#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 1;
vector<bool> resh(long long n) {
  vector<bool> v(n + 1, false);
  for (long long i = 3; i * i <= n; i += 2) {
    if (!v[i]) {
      for (long long j = i * i; j <= n; j += i) {
        v[j] = true;
      }
    }
  }
  return v;
}
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long binpow(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res *= a;
    a *= a;
    n >>= 1;
  }
  return res;
}
long long ei(long long n) {
  long long result = n;
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      result -= result / i;
    }
  if (n > 1) result -= result / n;
  return result;
}
void solve() {
  long long n;
  cin >> n;
  string v, v1;
  cin >> v1 >> v;
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    if (v[i] == '1') {
      if (v1[i] == '0') {
        ans++;
      } else if (i > 0 && v1[i - 1] == '1') {
        ans++;
        v1[i - 1] = '0';
      } else if (i < n && v1[i + 1] == '1') {
        ans++;
        v1[i + 1] = '0';
      }
    }
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
