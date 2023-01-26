#include <bits/stdc++.h>
const double PI = 3.1415926535897932384626433;
using namespace std;
struct edge {
  long long to, cost;
  edge() {}
  edge(long long a, long long b) { to = a, cost = b; }
};
const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
const int mod = 998244353;
struct mint {
  int x;
  mint(long long y = 0) {
    if (y < 0 || y >= mod) y = (y % mod + mod) % mod;
    x = y;
  }
  mint(const mint &ope) { x = ope.x; }
  mint operator-() { return mint(-x); }
  mint operator+(const mint &ope) { return mint(x) += ope; }
  mint operator-(const mint &ope) { return mint(x) -= ope; }
  mint operator*(const mint &ope) { return mint(x) *= ope; }
  mint operator/(const mint &ope) { return mint(x) /= ope; }
  mint &operator+=(const mint &ope) {
    x += ope.x;
    if (x >= mod) x -= mod;
    return *this;
  }
  mint &operator-=(const mint &ope) {
    x += mod - ope.x;
    if (x >= mod) x -= mod;
    return *this;
  }
  mint &operator*=(const mint &ope) {
    long long tmp = x;
    tmp *= ope.x, tmp %= mod;
    x = tmp;
    return *this;
  }
  mint &operator/=(const mint &ope) {
    long long n = mod - 2;
    mint mul = ope;
    while (n) {
      if (n & 1) *this *= mul;
      mul *= mul;
      n >>= 1;
    }
    return *this;
  }
  mint inverse() { return mint(1) / *this; }
  bool operator==(const mint &ope) { return x == ope.x; }
  bool operator!=(const mint &ope) { return x != ope.x; }
  bool operator<(const mint &ope) const { return x < ope.x; }
};
mint modpow(mint a, long long n) {
  if (n == 0) return mint(1);
  if (n % 2)
    return a * modpow(a, n - 1);
  else
    return modpow(a * a, n / 2);
}
istream &operator>>(istream &is, mint &ope) {
  long long t;
  is >> t, ope.x = t;
  return is;
}
ostream &operator<<(ostream &os, mint &ope) { return os << ope.x; }
ostream &operator<<(ostream &os, const mint &ope) { return os << ope.x; }
long long modpow(long long a, long long n, long long mod) {
  if (n == 0) return 1;
  if (n % 2)
    return ((a % mod) * (modpow(a, n - 1, mod) % mod)) % mod;
  else
    return modpow((a * a) % mod, n / 2, mod) % mod;
}
vector<mint> fact, fact_inv;
void make_fact(int n) {
  fact.resize(n + 1), fact_inv.resize(n + 1);
  fact[0] = mint(1);
  for (long long i = (1); (i) <= (n); (i)++) fact[i] = fact[i - 1] * mint(i);
  fact_inv[n] = fact[n].inverse();
  for (long long i = (n - 1); (i) >= (0); (i)--)
    fact_inv[i] = fact_inv[i + 1] * mint(i + 1);
}
mint comb(int n, int k) {
  if (n < 0 || k < 0 || n < k) return mint(0);
  return fact[n] * fact_inv[k] * fact_inv[n - k];
}
mint perm(int n, int k) { return comb(n, k) * fact[k]; }
vector<int> prime, pvec, qrime;
void make_prime(int n) {
  prime.resize(n + 1);
  for (long long i = (2); (i) <= (n); (i)++) {
    if (prime[i] == 0) pvec.push_back(i), prime[i] = i;
    for (auto p : pvec) {
      if (i * p > n || p > prime[i]) break;
      prime[i * p] = p;
    }
  }
}
void make_qrime(int n) {
  qrime.resize(n + 1);
  for (long long i = (2); (i) <= (n); (i)++) {
    int ni = i / prime[i];
    if (prime[i] == prime[ni])
      qrime[i] = qrime[ni] * prime[i];
    else
      qrime[i] = prime[i];
  }
}
bool exceed(long long x, long long y, long long m) { return x >= m / y + 1; }
void mark() { cout << "*" << endl; }
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
long long floor(long long a, long long b) {
  if (b < 0) a *= -1, b *= -1;
  if (a >= 0)
    return a / b;
  else
    return -((-a + b - 1) / b);
}
long long ceil(long long a, long long b) {
  if (b < 0) a *= -1, b *= -1;
  if (a >= 0)
    return (a + b - 1) / b;
  else
    return -((-a) / b);
}
long long modulo(long long a, long long b) {
  b = abs(b);
  return a - floor(a, b) * b;
}
long long sgn(long long x) {
  if (x > 0) return 1;
  if (x < 0) return -1;
  return 0;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long arith(long long x) { return x * (x + 1) / 2; }
long long arith(long long l, long long r) { return arith(r) - arith(l - 1); }
long long digitnum(long long x, long long b = 10) {
  long long ret = 0;
  for (; x; x /= b) ret++;
  return ret;
}
long long digitsum(long long x, long long b = 10) {
  long long ret = 0;
  for (; x; x /= b) ret += x % b;
  return ret;
}
string lltos(long long x) {
  string ret;
  for (; x; x /= 10) ret += x % 10 + '0';
  reverse((ret).begin(), (ret).end());
  return ret;
}
long long stoll(string &s) {
  long long ret = 0;
  for (auto c : s) ret *= 10, ret += c - '0';
  return ret;
}
template <typename T>
void uniq(T &vec) {
  sort((vec).begin(), (vec).end());
  vec.erase(unique((vec).begin(), (vec).end()), vec.end());
}
int popcount(unsigned long long x) {
  x -= ((x >> 1) & 0x5555555555555555ULL),
      x = (x & 0x3333333333333333ULL) + ((x >> 2) & 0x3333333333333333ULL);
  return (((x + (x >> 4)) & 0x0F0F0F0F0F0F0F0FULL) * 0x0101010101010101ULL) >>
         56;
}
template <class S, class T>
pair<S, T> &operator+=(pair<S, T> &s, const pair<S, T> &t) {
  s.first += t.first, s.second += t.second;
  return s;
}
template <class S, class T>
pair<S, T> &operator-=(pair<S, T> &s, const pair<S, T> &t) {
  s.first -= t.first, s.second -= t.second;
  return s;
}
template <class S, class T>
pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first + t.first, s.second + t.second);
}
template <class S, class T>
pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first - t.first, s.second - t.second);
}
template <class T>
T dot(const pair<T, T> &s, const pair<T, T> &t) {
  return s.first * t.first + s.second * t.second;
}
template <class T>
T cross(const pair<T, T> &s, const pair<T, T> &t) {
  return s.first * t.second - s.second * t.first;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &vec) {
  for (long long i = 0; (i) < (long long)(vec).size(); (i)++)
    os << vec[i] << " ";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  for (long long i = 0; (i) < (long long)(vec).size(); (i)++)
    os << vec[i] << " ";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, deque<T> &deq) {
  for (long long i = 0; (i) < (long long)(deq).size(); (i)++)
    os << deq[i] << " ";
  return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &ope) {
  os << "(" << ope.first << ", " << ope.second << ")";
  return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &ope) {
  os << "(" << ope.first << ", " << ope.second << ")";
  return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &ope) {
  for (auto p : ope) os << "(" << p.first << ", " << p.second << "),";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, set<T> &ope) {
  for (auto x : ope) os << x << " ";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, multiset<T> &ope) {
  for (auto x : ope) os << x << " ";
  return os;
}
template <typename T>
void outa(T a[], long long s, long long t) {
  for (long long i = (s); (i) <= (t); (i)++) {
    cout << a[i];
    if (i < t) cout << " ";
  }
  cout << endl;
}
void dump_func() { cout << endl; }
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&...tail) {
  cout << head;
  if (sizeof...(Tail) > 0) cout << " ";
  dump_func(std::move(tail)...);
}
long long n;
long long cnt[23][26];
mint sum[1 << 23];
template <typename T>
void zeta_transform(T a[], int n) {
  for (long long i = (0); (i) <= (n - 1); (i)++)
    for (long long j = (0); (j) <= ((1 << n) - 1); (j)++)
      if (j & (1 << i)) a[j] += a[j ^ (1 << i)];
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  string s;
  for (long long i = (0); (i) <= (n - 1); (i)++) {
    cin >> s;
    for (auto c : s) cnt[i][c - 'a']++;
  }
  long long N = 1 << n;
  for (long long i = (1); (i) <= (N - 1); (i)++) {
    long long mn[26];
    for (long long j = (0); (j) <= (25); (j)++) mn[j] = 2e18;
    for (long long j = (0); (j) <= (n - 1); (j)++) {
      if ((i & (1 << j)) == 0) continue;
      for (long long k = (0); (k) <= (25); (k)++)
        (mn[k]) = min((mn[k]), (cnt[j][k]));
    }
    sum[i] = 1;
    for (long long j = (0); (j) <= (25); (j)++) sum[i] *= (mn[j] + 1);
    if (popcount(i) % 2 == 0) sum[i] *= -1;
  }
  zeta_transform(sum, n);
  long long ans = 0;
  for (long long i = (1); (i) <= (N - 1); (i)++) {
    long long tmp = 0;
    for (long long j = (0); (j) <= (n - 1); (j)++) {
      if (i & (1 << j)) tmp += j + 1;
    }
    tmp *= popcount(i);
    tmp *= sum[i].x;
    ans ^= tmp;
  }
  dump_func(ans);
  return 0;
}
