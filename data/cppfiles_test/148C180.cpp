#include <bits/stdc++.h>
using namespace std;
const long long mod1 = 1000000007;
const long long mod2 = 998244353;
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
long long power(long long a, long long b) {
  long long result = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      result *= a;
    }
    a *= a;
    b /= 2;
  }
  return result;
}
long long gcd(long long x, long long y) {
  long long r;
  while (y != 0 && (r = x % y) != 0) {
    x = y;
    y = r;
  }
  return y == 0 ? x : y;
}
long long countSetBits(long long x) {
  long long Count = 0;
  while (x > 0) {
    if (x & 1) Count++;
    x = x >> 1;
  }
  return Count;
}
long long mod(long long x, long long M) { return ((x % M + M) % M); }
long long add(long long a, long long b, long long M) {
  return mod(mod(a, M) + mod(b, M), M);
}
long long mul(long long a, long long b, long long M) {
  return mod(mod(a, M) * mod(b, M), M);
}
long long powerM(long long a, long long b, long long M) {
  long long res = 1ll;
  while (b) {
    if (b % 2ll == 1ll) {
      res = mul(a, res, M);
    }
    a = mul(a, a, M);
    b /= 2ll;
  }
  return res;
}
void solve() {
  long long h, w;
  cin >> w >> h;
  long long x;
  cin >> x;
  vector<long long> v(x);
  for (long long i = 0; i < x; i++) {
    cin >> v[i];
  }
  long long y;
  cin >> y;
  vector<long long> v1(y);
  for (long long i = 0; i < y; i++) {
    cin >> v1[i];
  }
  long long z;
  cin >> z;
  vector<long long> v2(z);
  for (long long i = 0; i < z; i++) {
    cin >> v2[i];
  }
  long long a;
  cin >> a;
  vector<long long> v3(a);
  for (long long i = 0; i < a; i++) {
    cin >> v3[i];
  }
  sort(v.begin(), v.end());
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  sort(v3.begin(), v3.end());
  long long t = max(v[x - 1] - v[0], v1[y - 1] - v1[0]);
  long long ans1 = t * h;
  long long t1 = max(v2[z - 1] - v2[0], v3[a - 1] - v3[0]);
  long long ans2 = t1 * w;
  cout << max(ans2, ans1) << '\n';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(20);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
