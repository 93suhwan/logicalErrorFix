#include <bits/stdc++.h>
using namespace std;
const int32_t INFint = 1e9;
const long long INFll = 1e18;
const long long INF = 9e18;
const long double PI = acos(-1);
long long powersOfTwo[31] = {
    1,         2,         4,         8,        16,       32,       64,
    128,       256,       512,       1024,     2048,     4096,     8192,
    16384,     32768,     65536,     131072,   262144,   524288,   1048576,
    2097152,   4194304,   8388608,   16777216, 33554432, 67108864, 134217728,
    268435456, 536870912, 1073741824};
long long power(long long x, long long y) {
  long long r = 1;
  while (y > 0) {
    if (y & 1) r = r * x;
    y = y >> 1;
    x = x * x;
  }
  return r;
}
long long powerMod(long long x, long long y, long long p) {
  long long res = 1;
  x %= p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long log2n(long long n) { return (n > 1) ? 1 + log2n(n / 2) : 0; }
long long twoPower(long long n) { return (n) ? 2 * twoPower(n - 1) : 1; }
long long getMin(vector<long long> &mn, vector<long long> &test) {
  long long cx = 0;
  for (long long i = 0; i < 5; i++)
    if (test[i] < mn[i]) cx++;
  if (cx >= 3) mn = test;
  return cx;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long tt = 1;
  cin >> tt;
  long long tc = tt;
  while (tt--) {
    long long n;
    cin >> n;
    vector<vector<long long>> arr(n, vector<long long>(5));
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < 5; j++) {
        cin >> arr[i][j];
      }
    }
    vector<long long> mn(5, INFll);
    for (long long i = 0; i < n; i++) {
      getMin(mn, arr[i]);
    }
    bool isPassing = true;
    long long index = -1;
    for (long long i = 0; i < n; i++) {
      if (mn == arr[i]) index = i;
    }
    for (long long i = 0; i < n; i++) {
      if (i == index) continue;
      long long x = getMin(arr[i], mn);
      if (x < 3) isPassing = false;
    }
    if (isPassing)
      cout << index + 1 << '\n';
    else
      cout << -1 << '\n';
  }
  cerr << "Time : " << 1000 * (long double)clock() / (long double)CLOCKS_PER_SEC
       << "ms\n";
  ;
}
