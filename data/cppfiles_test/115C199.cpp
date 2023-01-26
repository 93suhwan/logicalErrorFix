#include <bits/stdc++.h>
clock_t startTime = clock();
using namespace std;
void io() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
double PI = 4 * atan(1);
long long mod = 1e9 + 7, mxn = 3e5 + 5;
void deb(vector<long long> v) {
  for (auto t : v) cerr << t << " ";
  cerr << "\n";
}
long long mul(long long a, long long b, long long mod) {
  a %= mod;
  b %= mod;
  a *= b;
  a += mod;
  return a % mod;
}
bool sortbysecdesc(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second > b.second;
}
bool check_sorted(vector<long long> a) {
  long long n = a.size();
  for (long long i = 1; i < n; i++) {
    if (a[i] >= a[i - 1]) continue;
    return false;
  }
  return true;
}
vector<long long> fact(2e5 + 5, 1);
long long binPow(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long ret = binPow(a, b / 2);
  if (b % 2 == 0) return (ret * ret) % mod;
  return ((ret * ret) % mod * a) % mod;
}
long long inv(long long a) { return (binPow(a, mod - 2) % mod + mod) % mod; }
long long binom(long long a, long long b) {
  if (b < 0 or a < 0) return 0;
  return (((fact[a] * inv(fact[b])) % mod * inv(fact[a - b])) % mod + mod) %
         mod;
}
vector<int> sieveOfEratosthenes(int N) {
  bool primes[N + 1];
  memset(primes, true, sizeof(primes));
  vector<int> arr;
  for (int i = 2; i * i <= N; i++)
    if (primes[i] == true) {
      for (int j = i * i; j <= N; j += i) primes[j] = false;
    }
  for (int i = 2; i <= N; i++)
    if (primes[i]) arr.emplace_back(i);
  return arr;
}
void prime_fact(long long n, vector<long long> &res) {
  while (n % 2 == 0) {
    res.push_back(2);
    n = n / 2;
  }
  for (long long i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      res.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) {
    res.push_back(n);
  }
}
bool valid_coordinate(long long x, long long y, long long n, long long m) {
  if (x < 0 || y < 0)
    return false;
  else if (x >= n || y >= m)
    return false;
  else
    return true;
}
int sod(int n) {
  int sum = 0;
  while (n) {
    sum += (n % 10);
    n /= 10;
  }
  return sum;
}
bool isPowerOfTwo(long long n) { return n && (!(n & (n - 1))); }
bool check(vector<long long> &a, long long h, long long mid) {
  long long cnt = 0;
  for (long long i = 0; i < a.size(); i++) {
    long long newVal = a[i] + mid;
    if (i + 1 < a.size() && a[i + 1] < newVal) {
      cnt += a[i + 1] - a[i];
    } else {
      cnt += mid;
    }
    if (cnt >= h) return true;
  }
  return false;
}
void solve() {
  long long n, h;
  cin >> n >> h;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long lo = 0, hi = 1e18;
  while (lo < hi) {
    long long mid = lo + (hi - lo) / 2;
    if (check(a, h, mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << lo << endl;
  return;
}
int main() {
  io();
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
