#include <bits/stdc++.h>
using namespace std;
int divisors(int n);
int fib(int n) {
  if (n <= 1) {
    return n;
  }
  return fib(n - 1) + fib(n - 2);
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int lcm(int a, int b) { return a * b / gcd(a, b); }
long long fac(int n) {
  if (n == 1) {
    return n;
  }
  return n * fac(n - 1);
}
int pow(int a, int b) {
  if (b == 0) return 1;
  int sum = pow(a, b / 2);
  sum *= sum;
  if (b % 2 != 0) sum *= a;
  return sum;
}
long long sumpow(long long a, int k) {
  if (k == 0) return 0;
  if (k % 2 == 1) return a * (1 + sumpow(a, k / 2 - 1));
  long long h = sumpow(a, k / 2 - 1);
  return h * (1 + h - sumpow(a, k / 2 - 1));
}
bool sbs(pair<int, int> &a, pair<int, int> &b) { return (a.first > b.first); }
long long f(long long n) {
  if (n == 1)
    return 1;
  else
    return n * f((n - 1));
}
bool so(string s, string z) { return s + z < z + s; }
bool sl(int a, int b) { return a > b; }
bool tprime(double n) {
  if (n == 1) return 0;
  long long N = n;
  if ((double)sqrt(n) != (long long)sqrt(N)) {
    return 0;
  }
  N = sqrt(N);
  for (long long i = 2; i * i <= N; i++) {
    if (!(N % i)) return 0;
  }
  return 1;
}
long long d(long long x) {
  if (x == 1 || x == 2) return x;
  long long c = 2;
  for (long long i = 2; i * i < x; i++) {
    if (x % i == 0) c += 2;
  }
  long long b = sqrt(x);
  if (b * b == x) c++;
  return c;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.size() % 2 != 0) {
      cout << "NO\n";
    } else {
      int c = 0;
      bool v = 1;
      for (int f = 0, l = s.size() / 2; f < s.size() / 2 && l < s.size();
           f++, l++) {
        if (s[f] != s[l]) {
          v = 0;
          break;
        }
      }
      if (v) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}
