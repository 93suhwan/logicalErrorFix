#include <bits/stdc++.h>
using namespace std;
void read(vector<long long>& v) {
  for (auto& a : v) cin >> a;
}
void print(vector<long long>& v) {
  for (auto& a : v) cout << a << ' ';
  cout << endl;
}
long long oo = 0x3f3f3f3f;
const long long N = 1 * 1e10 + 1;
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
  long long k = 1;
  for (long long i = 1; i < 100001; i++) {
    if (i * i >= n) {
      k = i;
      break;
    }
  }
  if (n > k * k - k) {
    cout << k << ' ' << (k * k + 1) - n << endl;
    return;
  }
  cout << n - ((k - 1) * (k - 1)) << ' ' << k << endl;
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
