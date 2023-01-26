#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const long double scale = 1e+9;
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long expo(long long a, long long b, long long mod) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
long long mminvprime(long long a, long long b) { return expo(a, b - 2, b); }
bool revsort(long long a, long long b) { return a > b; }
void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}
long long combination(long long n, long long r, long long m, long long *fact,
                      long long *ifact) {
  long long val1 = fact[n];
  long long val2 = ifact[n - r];
  long long val3 = ifact[r];
  return (((val1 * val2) % m) * val3) % m;
}
void google(int t) { cout << "Case #" << t << ": "; }
vector<long long> sieve(int n) {
  int *arr = new int[n + 1]();
  vector<long long> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
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
long long mod_div(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
long long phin(long long n) {
  long long number = n;
  if (n % 2 == 0) {
    number /= 2;
    while (n % 2 == 0) n /= 2;
  }
  for (long long i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      number = (number / i * (i - 1));
    }
  }
  if (n > 1) number = (number / n * (n - 1));
  return number;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long nextPrime(long long N) {
  if (N <= 1) return 2;
  long long prime = N;
  bool found = false;
  while (!found) {
    prime++;
    if (isPrime(prime)) found = true;
  }
  return prime;
}
bool palin(string s, long long i, long long j) {
  if (i > j) return false;
  while (i < j) {
    if (s[i] != s[j]) return false;
    i++;
    j--;
  }
  return true;
}
bool isperfect(long double x) {
  if (x >= 0) {
    long long s = sqrt(x);
    return (s * s == x);
  }
  return false;
}
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first < b.first;
}
long long power(long long num, long long p, long long m) {
  long long x = 1;
  while (p > 0) {
    if (p & 1) {
      x = (x * num) % m;
      num--;
    }
    num = (num * num) % m;
    p /= 2;
  }
  return x % m;
}
vector<long long> factor(long long x) {
  vector<long long> res;
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) res.push_back(i);
    while (x % i == 0) {
      x /= i;
    }
  }
  if (x != 1) res.push_back(x);
  return res;
}
long long inverseFact(long long n) {
  return power(n, 998244353 - 2, 998244353);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    long long i = 0;
    long long res = 0, res2 = 0;
    while (i < n) {
      if ((s[i] == '1' && t[i] == '0') || (t[i] == '1' && s[i] == '0')) {
        res += 2;
        i++;
        continue;
      } else if ((s[i] == '1' && t[i] == '1')) {
        if (i == n - 1) break;
        if ((s[i + 1] == '0' && t[i + 1] == '1') ||
            (s[i + 1] == '1' && t[i + 1] == '0')) {
          i += 2;
          res += 2;
        } else if (s[i + 1] == '0' && t[i + 1] == '0') {
          i += 2;
          res += 2;
        } else
          i++;
      } else {
        if (i == n - 1) {
          res += 1;
          break;
        }
        if (s[i + 1] == '1' && t[i + 1] == '1') {
          res += 2;
          i += 2;
        } else {
          res += 1;
          i++;
        }
      }
    }
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    i = 0;
    while (i < n) {
      if ((s[i] == '1' && t[i] == '0') || (t[i] == '1' && s[i] == '0')) {
        res2 += 2;
        i++;
      } else if ((s[i] == '1' && t[i] == '1')) {
        if (i == n - 1) break;
        if ((s[i + 1] == '0' && t[i + 1] == '1') ||
            (s[i + 1] == '1' && t[i + 1] == '0')) {
          i += 2;
          res2 += 2;
        } else if (s[i + 1] == '0' && t[i + 1] == '0') {
          i += 2;
          res2 += 2;
        } else
          i++;
      } else {
        if (i == n - 1) {
          res2 += 1;
          break;
        }
        if (s[i + 1] == '1' && t[i + 1] == '1') {
          res2 += 2;
          i += 2;
        } else {
          res2 += 1;
          i++;
        }
      }
    }
    cout << max(res2, res) << "\n";
  }
  return 0;
}
