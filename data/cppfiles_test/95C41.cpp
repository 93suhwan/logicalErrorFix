#include <bits/stdc++.h>
const double PI = 3.1415926535897932384626433;
using namespace std;
struct edge {
  long long to, cost;
  edge() {}
  edge(long long a, long long b) { to = a, cost = b; }
};
const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int mod = 998244353;
struct mint {
  int x;
  mint(long long y = 0) {
    if (y < 0 || y >= mod) y = (y % mod + mod) % mod;
    x = y;
  }
  mint(const mint& ope) { x = ope.x; }
  mint operator-() { return mint(-x); }
  mint operator+(const mint& ope) { return mint(x) += ope; }
  mint operator-(const mint& ope) { return mint(x) -= ope; }
  mint operator*(const mint& ope) { return mint(x) *= ope; }
  mint operator/(const mint& ope) { return mint(x) /= ope; }
  mint& operator+=(const mint& ope) {
    x += ope.x;
    if (x >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint& ope) {
    x += mod - ope.x;
    if (x >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint& ope) {
    long long tmp = x;
    tmp *= ope.x, tmp %= mod;
    x = tmp;
    return *this;
  }
  mint& operator/=(const mint& ope) {
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
  bool operator==(const mint& ope) { return x == ope.x; }
  bool operator!=(const mint& ope) { return x != ope.x; }
  bool operator<(const mint& ope) { return x < ope.x; }
};
mint modpow(mint a, long long n) {
  if (n == 0) return mint(1);
  if (n % 2)
    return a * modpow(a, n - 1);
  else
    return modpow(a * a, n / 2);
}
istream& operator>>(istream& is, mint& ope) {
  long long t;
  is >> t, ope.x = t;
  return is;
}
ostream& operator<<(ostream& os, mint& ope) { return os << ope.x; }
ostream& operator<<(ostream& os, const mint& ope) { return os << ope.x; }
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
vector<int> prime, pvec;
void make_prime(int n) {
  prime.resize(n + 1);
  for (long long i = (2); (i) <= (n); (i)++) {
    if (prime[i]) continue;
    for (int j = i; j <= n; j += i) prime[j] = i;
  }
  for (long long i = (2); (i) <= (n); (i)++)
    if (prime[i] == i) pvec.push_back(i);
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
long long stoll(string& s) {
  long long ret = 0;
  for (auto c : s) ret *= 10, ret += c - '0';
  return ret;
}
template <typename T>
void uniq(T& vec) {
  sort((vec).begin(), (vec).end());
  vec.erase(unique((vec).begin(), (vec).end()), vec.end());
}
template <class S, class T>
pair<S, T>& operator+=(pair<S, T>& s, const pair<S, T>& t) {
  s.first += t.first, s.second += t.second;
  return s;
}
template <class S, class T>
pair<S, T>& operator-=(pair<S, T>& s, const pair<S, T>& t) {
  s.first -= t.first, s.second -= t.second;
  return s;
}
template <class S, class T>
pair<S, T> operator+(const pair<S, T>& s, const pair<S, T>& t) {
  return pair<S, T>(s.first + t.first, s.second + t.second);
}
template <class S, class T>
pair<S, T> operator-(const pair<S, T>& s, const pair<S, T>& t) {
  return pair<S, T>(s.first - t.first, s.second - t.second);
}
template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
  for (long long i = 0; (i) < (long long)(vec).size(); (i)++)
    os << vec[i] << " ";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
  for (long long i = 0; (i) < (long long)(vec).size(); (i)++)
    os << vec[i] << " ";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, deque<T>& deq) {
  for (long long i = 0; (i) < (long long)(deq).size(); (i)++)
    os << deq[i] << " ";
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U>& ope) {
  os << "(" << ope.first << ", " << ope.second << ")";
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& ope) {
  os << "(" << ope.first << ", " << ope.second << ")";
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, map<T, U>& ope) {
  for (auto p : ope) os << "(" << p.first << ", " << p.second << "),";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, set<T>& ope) {
  for (auto x : ope) os << x << " ";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, multiset<T>& ope) {
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
void dump_func(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(Tail) > 0) cout << " ";
  dump_func(std::move(tail)...);
}
long long T;
long long h, w;
long long a[1000005];
long long Rmin[1000005], Rmax[1000005];
long long Bmax[1000005], Bmin[1000005];
long long ltmp[1000005], rtmp[1000005];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> h >> w;
    for (long long y = (0); (y) <= (h - 1); (y)++)
      for (long long x = (0); (x) <= (w - 1); (x)++) cin >> a[y * w + x];
    vector<pair<long long, long long> > vec;
    for (long long i = (0); (i) <= (h - 1); (i)++)
      vec.push_back(pair<long long, long long>(a[i * w], i));
    sort((vec).begin(), (vec).end()), reverse((vec).begin(), (vec).end());
    for (long long i = (0); (i) <= (w - 1); (i)++)
      ltmp[i] = 2e18, rtmp[i] = -2e18;
    for (long long i = 0; (i) < (long long)(vec).size(); (i)++) {
      long long id = vec[i].second;
      long long mn = 2e18;
      for (long long j = (0); (j) <= (w - 1); (j)++) {
        (ltmp[j]) = min((ltmp[j]), (mn));
        (ltmp[j]) = min((ltmp[j]), (a[id * w + j]));
        mn = ltmp[j];
      }
      long long mx = -2e18;
      for (long long j = (w - 1); (j) >= (0); (j)--) {
        (rtmp[j]) = max((rtmp[j]), (mx));
        (rtmp[j]) = max((rtmp[j]), (a[id * w + j]));
        mx = rtmp[j];
      }
      for (long long j = (0); (j) <= (w - 1); (j)++) {
        Rmin[i * w + j] = ltmp[j];
        Rmax[i * w + j] = rtmp[j];
      }
    }
    for (long long i = (0); (i) <= (w - 1); (i)++)
      ltmp[i] = -2e18, rtmp[i] = 2e18;
    for (long long i = (((long long)(vec).size()) - 1); (i) >= (0); (i)--) {
      long long id = vec[i].second;
      long long mx = -2e18;
      for (long long j = (0); (j) <= (w - 1); (j)++) {
        (ltmp[j]) = max((ltmp[j]), (mx));
        (ltmp[j]) = max((ltmp[j]), (a[id * w + j]));
        mx = ltmp[j];
      }
      long long mn = 2e18;
      for (long long j = (w - 1); (j) >= (0); (j)--) {
        (rtmp[j]) = min((rtmp[j]), (mn));
        (rtmp[j]) = min((rtmp[j]), (a[id * w + j]));
        mn = rtmp[j];
      }
      for (long long j = (0); (j) <= (w - 1); (j)++) {
        Bmin[i * w + j] = rtmp[j];
        Bmax[i * w + j] = ltmp[j];
      }
    }
    long long ans_i = -1, ans_j = -1;
    for (long long i = (0); (i) <= (((long long)(vec).size()) - 2); (i)++) {
      for (long long j = (0); (j) <= (w - 2); (j)++) {
        if (Rmin[i * w + j] > Bmax[(i + 1) * w + j] &&
            Rmax[i * w + (j + 1)] < Bmin[(i + 1) * w + (j + 1)]) {
          ans_i = i, ans_j = j;
          goto end;
        }
      }
    }
  end:;
    if (ans_i == -1) {
      no();
      continue;
    }
    yes();
    string s;
    for (long long i = (0); (i) <= (h - 1); (i)++) s += "B";
    for (long long i = (0); (i) <= (ans_i); (i)++) s[vec[i].second] = 'R';
    dump_func(s, ans_j + 1);
  }
  return 0;
}
