#include <bits/stdc++.h>
using namespace std;
namespace CF {
using ll = long long;
using vcs = vector<string>;
using ull = unsigned long long;
using vb = vector<bool>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using piii = pair<pii, int>;
using vpiii = vector<piii>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using pdd = pair<double, double>;
using vpdd = vector<pdd>;
using vl = vector<ll>;
using vi = vector<int>;
using vvl = vector<vl>;
using vvi = vector<vi>;
using vvvl = vector<vvl>;
using vvvi = vector<vvi>;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using pq = priority_queue<T, vector<T>, less<T>>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T1, typename T2>
pair<T1, T2>& operator+=(pair<T1, T2>& p1, const pair<T1, T2>& p2) {
  p1.first += p2.first, p1.second += p2.second;
  return p1;
}
template <typename T1, typename T2>
pair<T1, T2>& operator-=(pair<T1, T2>& p1, const pair<T1, T2>& p2) {
  p1.first -= p2.first, p1.second -= p2.second;
  return p1;
}
template <typename T1, typename T2>
pair<T1, T2> operator+(pair<T1, T2> p1, const pair<T1, T2>& p2) {
  return p1 += p2;
}
template <typename T1, typename T2>
pair<T1, T2> operator-(pair<T1, T2> p1, const pair<T1, T2>& p2) {
  return p1 -= p2;
}
template <typename T>
T operator*(const pair<T, T>& p1, const pair<T, T>& p2) {
  return p1.first * p2.first + p1.second * p2.second;
}
template <typename T>
T operator^(const pair<T, T>& p1, const pair<T, T>& p2) {
  return p1.first * p2.second - p2.first * p1.second;
}
template <typename T>
pair<T, T>& operator*=(pair<T, T>& p1, const T& p2) {
  p1.first *= p2;
  p1.second *= p2;
  return p1;
}
template <typename T>
pair<T, T> operator*(pair<T, T> p1, const T& p2) {
  return p1 *= p2;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  return os << p.first << ' ' << p.second;
}
template <typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, const vc<T>& a) {
  for (auto& v : a) os << v << ' ';
  return os;
}
template <typename T>
istream& operator>>(istream& is, vc<T>& a) {
  for (auto& v : a) is >> v;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, const vc<vc<T>>& a) {
  for (auto& v : a) os << v << endl;
  return os;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const map<T1, T2>& a) {
  for (auto& [v1, v2] : a) os << endl << setw(15) << v1 << " : " << v2 << ' ';
  return os;
}
template <typename T>
vc<T>& operator+=(vc<T>& a, const vc<T>& b) {
  for (auto& v : b) a.emplace_back(v);
  return a;
}
template <typename T>
vc<T> operator+(vc<T> a, const vc<T>& b) {
  return a += b;
}
template <typename T>
vc<T>& operator+=(vc<T>& a, const T& b) {
  for (auto& v : a) v += b;
  return a;
}
template <typename T>
vc<T> operator+(vc<T> a, const T& b) {
  return a += b;
}
template <typename T>
vc<T>& operator-=(vc<T>& a, const T& b) {
  for (auto& v : a) v -= b;
  return a;
}
template <typename T>
vc<T> operator-(vc<T> a, const T& b) {
  return a -= b;
}
template <typename T>
vc<T>& operator*=(vc<T>& a, const T& b) {
  for (auto& v : a) v *= b;
  return a;
}
template <typename T>
vc<T> operator*(vc<T> a, const T& b) {
  return a *= b;
}
template <typename T>
vc<T>& operator/=(vc<T>& a, const T& b) {
  for (auto& v : a) v /= b;
  return a;
}
template <typename T>
vc<T> operator/(vc<T> a, const T& b) {
  return a /= b;
}
template <typename T>
vc<T>& operator%=(vc<T>& a, const T& b) {
  for (auto& v : a) v %= b;
  return a;
}
template <typename T>
vc<T> operator%(vc<T> a, const T& b) {
  return a %= b;
}
template <typename T>
bool operator==(vc<T>& a, const T& b) {
  for (auto& v : a)
    if (v != b) return false;
  return true;
}
template <typename T>
bool operator!=(vc<T>& a, const T& b) {
  return !(a == b);
}
ll POW(ll a, ll b, ll p) {
  a %= p;
  if (a == 0) return 0LL;
  ll r = 1;
  for (; b > 0; a = a * a % p, b >>= 1)
    if (b & 1) r = r * a % p;
  return r;
}
int IOS = []() {
  ios::sync_with_stdio(0);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();
ll gcd(ll a, ll b) {
  if (a < b) swap(a, b);
  if (b != 0)
    while (b ^= a ^= b ^= a %= b)
      ;
  return a;
}
ll exgcd(ll a, ll b, ll& x, ll& y) {
  ll d = a;
  if (b != 0)
    d = exgcd(b, a % b, y, x), y -= (a / b) * x;
  else
    x = 1, y = 0;
  return d;
}
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
const double PI = acos(-1);
constexpr int inf = 0x3f3f3f3f;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
}  // namespace CF
using namespace CF;
constexpr int mod = 998244353;
constexpr int N = 500 + 5;
void solve(int caseT) {
  int n, m;
  cin >> n >> m;
  vvi a(n, vi(m));
  cin >> a;
  vvi Lmin(n, vi(m, 1e6 + 5)), Rmin(n, vi(m, 1e6 + 5));
  vvi Lmax(n, vi(m, 0)), Rmax(n, vi(m, 0));
  for (int i = 0; i < n; i++) {
    Lmin[i][0] = Lmax[i][0] = a[i][0];
    for (int j = 1; j < m; j++) Lmin[i][j] = min(Lmin[i][j - 1], a[i][j]);
    for (int j = 1; j < m; j++) Lmax[i][j] = max(Lmax[i][j - 1], a[i][j]);
    Rmin[i][m - 1] = Rmax[i][m - 1] = a[i][m - 1];
    for (int j = m - 2; j >= 0; j--) Rmin[i][j] = min(Rmin[i][j + 1], a[i][j]);
    for (int j = m - 2; j >= 0; j--) Rmax[i][j] = max(Rmax[i][j + 1], a[i][j]);
  }
  for (int k = 0; k < m - 1; k++) {
    0;
    vi b(n);
    for (int i = 0; i < n; i++) b[i] = i;
    sort(begin(b), end(b),
         [&Lmin, &k](int f1, int f2) { return Lmin[f1][k] < Lmin[f2][k]; });
    vi umax(n, Lmax[b[0]][k]), Rumin(n, Rmin[b[0]][k + 1]),
        Rdmax(n, Rmax[b[n - 1]][k + 1]);
    for (int i = 1; i < n; i++) umax[i] = max(umax[i - 1], Lmax[b[i]][k]);
    for (int i = 1; i < n; i++) Rumin[i] = min(Rumin[i - 1], Rmin[b[i]][k + 1]);
    for (int i = n - 2; i >= 0; i--)
      Rdmax[i] = max(Rdmax[i + 1], Rmax[b[i]][k + 1]);
    for (int i = 0; i < n - 1; i++) {
      if (umax[i] < Lmin[b[i + 1]][k] && Rumin[i] > Rdmax[i + 1]) {
        string s(n, 'R');
        for (int q = 0; q <= i; q++) s[b[q]] = 'B';
        cout << "YES" << '\n' << s << ' ' << k + 1 << '\n';
        return;
      }
    }
  }
  cout << "NO" << '\n';
}
void init() {}
int main() {
  init();
  int T = 1;
  cin >> T;
  for (int i = 1; i <= T; i++) solve(i);
  cout.flush();
  return 0;
}
