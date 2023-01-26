#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long int min(long long int a, long long int b) {
  if (a < b)
    return a;
  else
    return b;
}
long long int max(long long int a, long long int b) {
  if (a > b)
    return a;
  else
    return b;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long int poww(long long int base, long long int exp) {
  base %= mod;
  long long int result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return result;
}
long long int mod_inverse(long long int x) { return poww(x, mod - 2); }
long long int extendedGCD(long long int a, long long int b, long long int& x,
                          long long int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long int x1, y1;
  long long int d = extendedGCD(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
long long int mod_inv_non_prime(long long int num, long long int mod) {
  long long int x, y;
  extendedGCD(num, mod, x, y);
  if (x < 0) return (x + mod) % mod;
  return x;
}
long long int mod_add(long long int a, long long int b) {
  a = a % mod;
  b = b % mod;
  return (a + b) % mod;
}
long long int mod_mul(long long int a, long long int b) {
  a = a % mod;
  b = b % mod;
  return (a * b) % mod;
}
long long int mod_sub(long long int a, long long int b) {
  a = a % mod;
  b = b % mod;
  return (((a - b) % mod) + mod) % mod;
}
long long int mod_div(long long int a, long long int b) {
  a = a % mod;
  return (a * mod_inverse(b)) % mod;
}
bool compare(long long int a, long long int b) { return a > b; }
vector<int> primes;
const int N = 10000001;
bool isPrime[N];
void sieve() {
  isPrime[0] = 0;
  isPrime[1] = 0;
  isPrime[2] = 1;
  for (int i = 3; i < N; i += 2) isPrime[i] = 1;
  for (int i = 4; i < N; i += 2) isPrime[i] = 0;
  primes.push_back(2);
  for (long long int i = 3; i < N; i++) {
    if (isPrime[i] == 1) {
      primes.push_back(i);
      for (long long int j = i * i; j < N; j += i) isPrime[j] = 0;
    }
  }
}
void precision(int a) { cout << setprecision(a) << fixed; }
bool isEqual(double a, double b) {
  double epsilon = 0.000001;
  return abs(a - b) < epsilon;
}
void google() {
  int t;
  cin >> t;
  for (int x = 1; x <= t; x++) {
    cout << "Case #" << x << ": ";
  }
}
int query() {
  cout << "? " << endl;
  int value;
  cin >> value;
  return value;
}
void interactive() {
  int val = query();
  cout << "! " << endl << flush;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  sieve();
  int t;
  t = 1;
  while (t--) {
    int num;
    cin >> num;
    if (num > 9)
      cout << num / 10 << endl;
    else if (num == 9)
      cout << 1 << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
