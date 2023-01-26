#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(long long n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
long long powermod(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
bool isPerfectSquare(long long x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void gourav_sv() {
  long long n, a, b;
  cin >> n >> a >> b;
  if (a == b || a == b - 1 || b == a - 1) {
    if (a == b) {
      cout << 1 << " ";
      for (long long i = 1; i <= a; i++)
        cout << 2 * i + 1 << " " << 2 * i << " ";
      for (long long i = 2 * (a + 1); i <= n; i++) cout << i << " ";
      cout << "\n";
    }
    if (a == b - 1) {
      for (long long i = 1; i <= b; i++)
        cout << 2 * i << " " << 2 * i - 1 << " ";
      for (long long i = 2 * b + 1; i <= n; i++) cout << i << " ";
      cout << "\n";
    }
    if (b == a - 1) {
      cout << 1 << " ";
      for (long long i = 1; i <= a; i++)
        cout << n - i + 1 << " " << n - i - 1 << " ";
      for (long long i = n - a - 1; i >= 2; i--) cout << i << " ";
      cout << "\n";
    }
  } else
    cout << -1 << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    gourav_sv();
  }
}
