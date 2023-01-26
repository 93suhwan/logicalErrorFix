#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <typename T, typename S>
ostream &operator<<(ostream &os, const pair<T, S> &v);
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v);
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v);
template <typename T, typename S>
ostream &operator<<(ostream &os, const map<T, S> &v);
template <typename T, typename S>
istream &operator>>(istream &inp, pair<T, S> &p);
template <typename T>
istream &operator>>(istream &inp, vector<T> &v);
template <class T>
inline bool remax(T &, T);
template <class T>
inline bool remin(T &, T);
template <class T>
T myceil(T, T);
long long md = 10;
long long my_gcd(long long, long long);
long long pw(long long, long long);
long long modinv(long long);
inline long long add(long long, long long);
inline long long subt(long long, long long);
inline long long mult(long long, long long);
long long ncr(long long, long long);
inline long long kthbit(long long n, long long k) {
  return (n & (1ll << k)) > 0;
}
long long R(long long B) {
  static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  return (unsigned long long)rng() % B;
}
void pre();
long long dx[4] = {0, 1, 0, -1};
long long dy[4] = {1, 0, -1, 0};
const long long MXSZ = 2;
long long fact[MXSZ];
long long mi[MXSZ];
void solvetestcase(long long tcn) {
  long long n;
  cin >> n;
  vector<long long> a(n);
  cin >> a;
  vector<array<long long, 3>> ans;
  for (long long i = 0; i < n; i++) {
    long long mn = i;
    for (long long j = i; j < n; j++) {
      if (a[j] < a[mn]) mn = j;
    }
    if (mn == i) continue;
    ans.push_back({i + 1, mn + 1, mn - i});
    for (long long j = mn; j >= i + 1; j--) {
      swap(a[j], a[j - 1]);
    }
  }
  cout << ans.size() << '\n';
  for (auto x : ans) {
    cout << x[0] << " " << x[1] << " " << x[2] << '\n';
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  md = 1e9 + 7;
  long long t = 1;
  cin >> t;
  for (long long i = 1; i < t + 1; i++) {
    solvetestcase(i);
  }
};
long long ncr(long long n, long long r) {
  if (!n) return 1;
  return mult(fact[n], mult(mi[r], mi[n - r]));
}
void pre() {
  fact[0] = 1;
  long long lim = MXSZ;
  for (long long i = 1; i < lim; i++) fact[i] = mult(i, fact[i - 1]);
  for (long long i = 0; i < lim; i++) mi[i] = modinv(fact[i]);
}
long long my_gcd(long long n, long long m) {
  if (n < m) swap(n, m);
  if (m == 0) return n;
  if (n == 0) return 0;
  if (n % m == 0) return m;
  while (m > 0) {
    n = n % m;
    swap(n, m);
  }
  return n;
}
long long pw(long long a, long long b) {
  long long c = 1, m = a % md;
  while (b) {
    if (b & 1) c = (c * m) % md;
    m = (m * m) % md;
    b /= 2;
  }
  return c;
}
long long modinv(long long n) { return pw(n, md - 2); }
inline long long add(long long a, long long b) {
  return (md + a % md + b % md) % md;
}
inline long long subt(long long a, long long b) {
  return (a % md - b % md + md) % md;
}
inline long long mult(long long a, long long b) {
  return (1ll * (a % md) * (b % md)) % md;
}
template <class T>
inline bool remax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
inline bool remin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
T myceil(T a, T b) {
  if (a % b)
    return (a / b) + 1;
  else
    return a / b;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, const pair<T, S> &v) {
  os << v.first << " " << v.second << '\n';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (long long i = 0; i < v.size(); ++i) {
    os << v[i] << " ";
  }
  os << '\n';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  for (auto i : v) os << i << " ";
  os << '\n';
  return os;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, const map<T, S> &v) {
  for (auto pp : v) os << pp.first << " " << pp.second << '\n';
  return os;
}
template <typename T, typename S>
istream &operator>>(istream &inp, pair<T, S> &p) {
  inp >> p.first >> p.second;
  return inp;
}
template <typename T>
istream &operator>>(istream &inp, vector<T> &v) {
  for (long long i = 0; i < v.size(); i++) inp >> v[i];
  return inp;
}
