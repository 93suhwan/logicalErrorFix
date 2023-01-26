#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << ", ";
  return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, set<T> S) {
  os << "{ ";
  for (auto s : S) os << s << ", ";
  return os << "}";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> M) {
  os << "{ ";
  for (auto m : M) os << "(" << m.F << ":" << m.S << ") ";
  return os << "}";
}
template <class T, class G, class F>
long long __pow(T a, G b, F p) {
  long long res = 1, mult = a % p;
  while (b > 0) {
    if (b & 1) {
      res = (unsigned long long)res * mult % p;
    }
    b >>= 1;
    mult = (unsigned long long)mult * mult % p;
  }
  return res;
}
int modinv(int a, int n) { return (int)__pow(a, n - 2, n); }
template <class T>
long long __pow(T a, T b) {
  long long res = 1, mult = a;
  while (b > 0) {
    if (b & 1) res = res * mult;
    b >>= 1;
    mult *= mult;
  }
  return res;
}
template <class T>
T exgcd(T a, T b, T &m, T &n) {
  if (b == 0) {
    m = 1;
    n = 0;
    return a;
  }
  T g = exgcd(b, a % b, m, n), k = n;
  n = m - (b / a) * n;
  m = k;
  return g;
}
template <class T>
T gcd(T a, T b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
void sieve(vector<int> &s) {
  int n = s.size();
  for (int i = 2; i < n + 1; i++) {
    if (s[i] != -1) continue;
    for (int j = i * 2; j < n + 1; j += i) s[j] = i;
  }
  return;
}
template <class T>
bool check_composite(T, T, T, int);
template <class T>
bool isPrime(T);
int c;
void check(vector<int> &a, int i, int s) {
  if (i == a.size()) {
    if (s == 0) c++;
    return;
  }
  check(a, i + 1, s);
  check(a, i + 1, s + a[i]);
  check(a, i + 1, s - a[i]);
  return;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  c = 0;
  check(a, 0, c);
  cout << (c > 1 ? "YES" : "NO");
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
    cout << "\n";
    ;
  }
  return 0;
}
template <class T>
bool check_composite(T n, T a, T d, int s) {
  T x = __mpow(a, d, n);
  if (x == 1 || x == n - 1) return false;
  for (int i = 1; i < s; i++) {
    x = (unsigned long long)x * x % n;
    if (x == n - 1) return false;
  }
  return true;
}
template <class T>
bool isPrime(T n) {
  if (n < 4) return (n == 2 || n == 3);
  if (n % 2 == 0) return false;
  int s = 0;
  long long d = n - 1;
  while (!(d & 1)) {
    d >>= 1;
    s++;
  }
  for (long long x : {5, 13, 19, 73, 193, 407521, 299210837}) {
    if (n == x) return true;
  }
  for (long long a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
    if (check_composite((long long)n, a, d, s)) return false;
  }
  return true;
}
