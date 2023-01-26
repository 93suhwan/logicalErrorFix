#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a, long long b) { return a > b; }
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long fib(long long n) {
  double phi = (1 + sqrt(5)) / 2;
  return (long long)round(pow(phi, n) / sqrt(5));
}
vector<long long> factors(long long n) {
  vector<long long> v;
  for (long long i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i) {
        v.push_back(i);
      } else {
        v.push_back(i);
        v.push_back(n / i);
      }
    }
  }
  sort(v.begin(), v.end());
  return v;
}
vector<long long> sieve(long long n) {
  vector<long long> v;
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (long long p = 2; p <= n; p++) {
    if (prime[p]) v.push_back(p);
  }
  sort(v.begin(), v.end());
  return v;
}
set<long long> prime(long long n) {
  set<long long> s;
  while (n % 2 == 0) {
    s.insert(2);
    n = n / 2;
  }
  for (long long i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      s.insert(i);
      n = n / i;
    }
  }
  if (n > 2) s.insert(n);
  return s;
}
string decToBinary(int n) {
  string s = "";
  int i = 0;
  while (n > 0) {
    s = to_string(n % 2) + s;
    n = n / 2;
    i++;
  }
  return s;
}
long long binaryToDecimal(string n) {
  string num = n;
  long long dec_value = 0;
  int base = 1;
  int len = num.length();
  for (int i = len - 1; i >= 0; i--) {
    if (num[i] == '1') dec_value += base;
    base = base * 2;
  }
  return dec_value;
}
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
bool isPowerOfTwo(int n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
long long mod = 10;
long long power(long long a, long long pow, long long mod) {
  long long res = 1;
  while (pow) {
    if (pow % 2 == 0) {
      a = (a * a) % mod;
      pow /= 2;
    } else {
      res = (res * a) % mod;
      pow--;
    }
  }
  return (res % mod);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    long long sum = a + b * 2 + c * 3;
    cout << sum % 2 << "\n";
  }
  return 0;
}
