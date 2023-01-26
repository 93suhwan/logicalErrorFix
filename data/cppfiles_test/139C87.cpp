#include <bits/stdc++.h>
double PI = 3.14159265358979323846;
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
bool isprime(long long int a) {
  if (a == 1) return false;
  for (int i = 2; i <= sqrt(a); i++) {
    if (a % i == 0) return false;
  }
  return true;
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
int prefixzero(int x) { return __builtin_clz(x); }
int suffixzero(int x) { return __builtin_ctz(x); }
int numberone(int x) { return __builtin_popcount(x); }
void read(vector<int> &v, int n) {
  for (int i = 0; i < n; i++) cin >> v[i];
}
void readl(vector<long long int> &v, long long int n) {
  for (long long int i = 0; i < n; i++) cin >> v[i];
}
vector<bool> sprime(int n) {
  vector<bool> prime(n + 1, true);
  prime[0] = false;
  prime[1] = false;
  for (long long int i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (long long int j = i * i; j <= n; j += i) prime[j] = false;
    }
  }
  return prime;
}
tuple<int, int, int> GCD(int a, int b) {
  if (b == 0)
    return {1, 0, a};
  else {
    int x, y, g;
    tie(x, y, g) = GCD(b, a % b);
    return {y, x - (a / b) * y, g};
  }
}
long long int pw(long long int base, long long int power, long long int mode) {
  long long int res = 1;
  base = base % mode;
  while (power != 0) {
    if (power & 1) {
      power -= 1;
      res = (res * base) % mode;
    } else {
      power /= 2;
      base = (base * base) % mode;
    }
  }
  return res;
}
vector<long long int> factor(long long int n) {
  vector<long long int> fac;
  for (long long int i = 2; i <= sqrt(n); i++) {
    while (n % i == 0) {
      fac.push_back(i);
      n /= i;
    }
  }
  if (n != 1) fac.push_back(n);
  return fac;
}
bool sol(long long int a, long long int b, long long int c) {
  if (c % gcd(a, b) == 0) {
    long long int m = c / gcd(a, b);
    double x1, y1, g;
    tie(x1, y1, g) = GCD(a, b);
    x1 *= m;
    y1 *= m;
    long long int x2 = ceil(-1.0 * x1 * (g / b));
    long long int y2 = floor(y1 * (g / a) * 1.0);
    if (x2 <= y2) return true;
  }
  return false;
}
pair<long long int, long long int> fib(long long int n) {
  if (n == 0) return {0, 1};
  auto p = fib(n >> 1);
  long long int c = p.first * (2 * p.second - p.first);
  long long int d = p.first * p.first + p.second * p.second;
  if (n & 1)
    return {d, c + d};
  else
    return {c, d};
}
long long int gethash(string &keys) {
  long long int p = 31;
  long long int m = 1e9 + 9;
  long long int hash_value = 0;
  long long int p_pow = 1;
  for (char c : keys) {
    hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
    p_pow = (p_pow * p) % m;
  }
  return hash_value;
}
vector<int> p_prefix(string s) {
  int n = s.size();
  vector<int> pi(n);
  int j = 0;
  for (int i = 1; i < n; i++) {
    j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
class dsu {
  vector<int> par, rnk;

 public:
  dsu(int n) {
    par = vector<int>(n + 1);
    rnk = vector<int>(n + 1, 1);
    for (int i = 1; i <= n; i++) par[i] = i;
  }
  int find_set(int a) {
    if (par[a] == a) return a;
    return par[a] = find_set(par[a]);
  }
  void Union_set(int a, int b) {
    int p1 = find_set(a);
    int p2 = find_set(b);
    if (p1 == p2) return;
    if (rnk[p1] < rnk[p2]) swap(p1, p1);
    par[p2] = p1;
    rnk[p1] += rnk[p2];
  }
};
bool isvalid(vector<int> &v, int i, int j, int x) {
  if (i >= j) return true;
  if (v[i] == v[j])
    return isvalid(v, i + 1, j - 1, x);
  else {
    if (x == 0)
      return isvalid(v, i + 1, j, v[i]) || isvalid(v, i, j - 1, v[j]);
    else {
      if (x == v[i]) return isvalid(v, i + 1, j, x);
      if (x == v[j])
        return isvalid(v, i, j - 1, x);
      else
        return false;
    }
  }
}
void solve() {
  string s;
  cin >> s;
  int n = s.length();
  if (n % 2) {
    cout << "No" << endl;
    return;
  } else {
    for (int i = 0; i < n / 2; i++) {
      if (s[i] != s[i + n / 2]) {
        cout << "No" << endl;
        return;
      }
    }
    cout << "YES" << endl;
    return;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
