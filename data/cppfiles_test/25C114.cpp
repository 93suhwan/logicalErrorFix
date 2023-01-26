#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n);
void fast();
void clk();
long long fact(long long n);
long long nCr(long long n, long long r);
long long gcd(long long a, long long b);
long long expo(long long a, long long b, long long m);
long long mod_add(long long a, long long b, long long m);
long long mod_mul(long long a, long long b, long long m);
long long mod_sub(long long a, long long b, long long m);
long long lcm(long long a, long long b);
long long msbof(long long n);
bool isPrime(long long n);
void primeFactors(long long n);
bool isPowerOfTwo(long long n);
long long cnty = 0;
void solve(long long sz) {
  string s, t;
  cin >> s >> t;
  long long nt = t.size();
  long long n = s.size();
  cnty++;
  bool pos = 0;
  cnty++;
  cnty++;
  for (long long i = 0; i < n; i++) {
    for (long long j = 1; j < min(nt + 1, n - i + 1); j++) {
      string temp = s.substr(i, j);
      cnty++;
      cnty++;
      string temp2;
      if (i + j - (nt - j) - 1 >= 0) {
        temp2 = s.substr(i + j - (nt - j) - 1, nt - j);
        cnty++;
        cnty++;
        reverse(temp2.begin(), temp2.end());
      } else
        continue;
      temp += temp2;
      cnty++;
      cnty++;
      cnty++;
      if (t == temp) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}
int main() {
  fast();
  long long t = 1;
  cin >> t;
  while (t--) {
    solve(t);
  }
  return 0;
}
void fast() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
bool isPowerOfTwo(long long n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
long long nCr(long long n, long long r) {
  return fact(n) / (fact(r) * fact(n - r));
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; i++) res = res * i;
  return res;
}
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long expo(long long a, long long b, long long m) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % 1000000007;
    a = (a * a) % 1000000007;
    b = b >> 1;
  }
  return res;
}
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long msbof(long long n) {
  if (n == 0) return 0;
  long long msb = 0;
  n = n / 2;
  while (n != 0) {
    n = n / 2;
    msb++;
  }
  return (1 << msb);
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
