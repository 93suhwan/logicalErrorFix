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
  long long n, d;
  cin >> n >> d;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  queue<long long> q;
  long long dist[n];
  for (long long i = 0; i < n; i++) dist[i] = INT_MAX;
  for (long long i = 0; i < n; i++) {
    if (a[i] == 0) {
      q.push(i);
      dist[i] = 0;
    }
  }
  while (q.size() > 0) {
    long long x = q.front();
    q.pop();
    long long y = (x + d) % n;
    if (a[y] == 1) {
      dist[y] = dist[x] + 1;
      q.push(y);
    }
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    ans = max(ans, dist[i]);
  }
  if (ans == INT_MAX)
    cout << -1;
  else
    cout << ans;
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
