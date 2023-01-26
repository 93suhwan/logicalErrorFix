#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(char s) { return string(1, s); }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A>
string to_string(A);
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool f = 1;
  string r = "{";
  for (const auto& x : v) {
    if (!f) r += ", ";
    f = 0;
    r += to_string(x);
  }
  return r + "}";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
long long mod(long long n);
long long gcd(long long a, long long b);
long long modM(long long n, long long m);
long long modA(long long n, long long m);
long long modS(long long n, long long m);
long long power(long long a, long long b);
long long inv(long long a, long long mod);
const long long int N = 1e9 + 7;
void solve() {
  long long n;
  string s;
  cin >> n >> s;
  for (long long i = 0; i < (long long)(n / 2); ++i) {
    if (s[n - 1 - i] == '0') {
      cout << 1 << " " << n - i << " " << 1 << " " << n - i - 1 << "\n";
      return;
    }
  }
  for (long long i = 0; i < (long long)(n / 2); ++i) {
    if (s[i] == '0') {
      cout << i + 1 << " " << n << " " << i + 2 << " " << n << "\n";
      return;
    }
  }
  if (s[n / 2] == '0') {
    cout << 1 << " " << n / 2 + 1 << " " << n / 2 + 1 << " " << n << "\n";
    return;
  }
  if (n & 1) {
    n--;
  }
  cout << 1 << " " << n << " " << 1 << " " << n / 2 << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(6);
  cout << fixed;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
long long gcd(long long a, long long b) {
  if (b > a) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long mod(long long n) { return (n % N + N) % N; }
long long modM(long long n, long long m) { return ((n % N * m % N) + N) % N; }
long long modA(long long n, long long m) { return ((n % N + m % N) + N) % N; }
long long modS(long long n, long long m) { return ((n % N - m % N) + N) % N; }
long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = modM(res, a);
    }
    a = modM(a, a);
    b >>= 1;
  }
  return res;
}
long long inv(long long a, long long mod) {
  a %= mod;
  if (a < 0) a += mod;
  long long b = mod, u = 0, v = 1;
  while (a) {
    long long t = b / a;
    b -= t * a;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += mod;
  return u;
}
