#include <bits/stdc++.h>
using namespace std;
const long long N = (long long)(5 * 1e5 + 10);
void precision(long long a) { cout << setprecision(a) << fixed; }
long long expo(long long a, long long b, long long m) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b = b >> 1;
  }
  return res;
}
long long GCD(long long A, long long B) { return (B) ? GCD(B, A % B) : A; }
long long LCM(long long A, long long B) { return A * B / GCD(A, B); }
long long max(long long A, long long B) { return (A >= B) ? A : B; }
long long min(long long A, long long B) { return (A <= B) ? A : B; }
long long ceil_div(long long a, long long b) {
  return a % b == 0 ? a / b : a / b + 1;
}
template <typename T>
istream &operator>>(istream &istream, vector<T> &v) {
  for (auto &it : v) {
    cin >> it;
  }
  return istream;
}
bool isPrime(long long n) {
  if (n == 1) return false;
  if (n == 2) return true;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
void rec(long long n) {
  cout << (long long)sqrt(n) + (long long)cbrt(n) - (long long)(sqrt(cbrt(n)))
       << "\n";
}
void sol() {
  long long n;
  cin >> n;
  rec(n);
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long t = 1;
  cin >> t;
  while (t--) {
    sol();
  }
  return 0;
}
