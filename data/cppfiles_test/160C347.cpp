#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long power(long long a, long long b, long long p) {
  if (a == 0) return 0;
  long long res = 1;
  if (a >= p) a = a % p;
  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    b >>= 1;
    a = (a * a) % p;
  }
  return res;
}
vector<long long> decToBinary(long long n) {
  vector<long long> v;
  for (long long i = 31; i >= 0; i--) {
    long long k = n >> i;
    if (k & 1)
      v.push_back(1);
    else
      v.push_back(0);
  }
  return v;
}
long long binarySearch(long long arr[], long long l, long long r, long long x) {
  if (r >= l) {
    long long mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
long long maxResult(long long n, long long a, long long b, long long c) {
  long long maxVal = 0;
  for (long long i = 0; i <= n; i += a)
    for (long long j = 0; j <= n - i; j += b) {
      float z = (float)(n - (i + j)) / c;
      if (floor(z) == ceil(z)) {
        long long x = i / a;
        long long y = j / b;
        maxVal = max(maxVal, x + y + (long long)z);
      }
    }
  return maxVal;
}
void SeiveOfEratosthenes(long long n) {
  bool prime[n + 1];
  vector<long long> v;
  memset(prime, true, sizeof(prime));
  for (long long i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (long long j = i * i; j <= n; j += i) {
        prime[j] = false;
      }
    }
  }
  for (long long i = 2; i <= n; i++) {
    if (prime[i]) {
      v.push_back(i);
    }
  }
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
void solve() {
  long long n, m;
  long long x, y;
  long long r, c;
  cin >> n >> m >> x >> y >> r >> c;
  long long val = 0;
  if (r >= x) {
    val = r - x;
  } else {
    val = n - x + (n - r);
  }
  long long val1 = 0;
  if (c >= y) {
    val1 = c - y;
  } else {
    val1 = m - y + (m - c);
  }
  cout << min(val, val1) << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  long long r = 1;
  while (t--) {
    solve();
  }
}
