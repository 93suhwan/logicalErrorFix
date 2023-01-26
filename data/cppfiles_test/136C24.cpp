#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
const long long MAX_N = 1e5 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long double EPS = 1e-9;
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long res = binpow(a, b / 2);
  if (b % 2)
    return res * res * a;
  else
    return res * res;
}
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long etf(long long n) {
  if (n == 1) return 1;
  long long phi = n;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      phi = phi - phi / i;
    }
  }
  if (n > 1) phi = phi - phi / n;
  return phi;
}
void solve() {
  long long n;
  cin >> n;
  long long b[n];
  long long f = (n * (n + 1)) / 2;
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> b[i];
    sum += b[i];
  }
  if (sum % f != 0) {
    cout << "NO\n";
    return;
  }
  long long suma = sum / f;
  long long a[n];
  a[0] = (suma - (b[0] - b[n - 1])) / n;
  if ((suma - (b[0] - b[n - 1])) % n != 0 || (suma - (b[0] - b[n - 1])) <= 0) {
    cout << "NO\n";
    return;
  }
  for (long long i = 1; i < n; i++) {
    long long dif = b[i] - b[i - 1];
    if ((suma - dif) % n != 0 || (suma - dif) <= 0) {
      cout << "NO\n";
      return;
    }
    a[i] = (suma - dif) / n;
  }
  cout << "YES\n";
  for (long long i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tc = 1;
  cin >> tc;
  for (long long t = 1; t <= tc; t++) {
    solve();
  }
}
