#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
const long long MOD = 1000000007, OO = 0x3f3f3f3f;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
void init() {
  cin.tie(0);
  cin.sync_with_stdio(0);
}
long long power(long long a, long long b, long long mod) {
  if (!b) return 1ll;
  if (b == 1) return a % mod;
  long long r = power(a, b / 2ll, mod) % mod;
  if (b % 2ll)
    return ((r * (a % mod) % mod) * r) % mod;
  else
    return (r * r) % mod;
}
long long nCr(long long n, long long m) {
  return (m == 0) ? 1 : n * nCr(n - 1, m - 1) / m;
}
bool checkDivisibility(long long n, int digit) {
  return (digit == 0 || (digit != 0 && n % digit == 0));
}
bool allDigitsDivide(long long n) {
  long long temp = n;
  while (temp > 0) {
    long long digit = temp % 10;
    if (!(checkDivisibility(n, digit))) return false;
    temp /= 10;
  }
  return true;
}
bool comp2(long long a, long long b) { return a > b; }
int gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int power2(int a, unsigned int n, int p) {
  int res = 1;
  a = a % p;
  while (n > 0) {
    if (n & 1) res = (res * a) % p;
    n = n >> 1;
    a = (a * a) % p;
  }
  return res;
}
bool isPrime(unsigned int n, int k) {
  if (n <= 1 || n == 4) return false;
  if (n <= 3) return true;
  while (k > 0) {
    int a = 2 + rand() % (n - 4);
    if (gcd(n, a) != 1) return false;
    if (power2(a, n - 1, n) != 1) return false;
    k--;
  }
  return true;
}
vector<int> primes;
void SieveOfEratosthenes(int n) {
  vector<bool> prime(n + 1, true);
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (int p = 2; p <= n; p++)
    if (prime[p]) primes.push_back(p);
}
const long long N = 1e5 + 5;
void TLE() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort((a).begin(), (a).end());
  int mn = a[0];
  int all_donated = 0;
  for (int i = 0; i < n; i++) {
    all_donated += abs(mn - a[i]);
  }
  if (all_donated % n == 0)
    cout << 0 << "\n";
  else
    cout << 1 << "\n";
}
int main() {
  init();
  int tt = 0;
  cin >> tt;
  while (tt--) TLE();
}
