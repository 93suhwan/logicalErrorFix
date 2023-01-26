#include <bits/stdc++.h>
using namespace std;
using vi = vector<long long>;
template <typename T>
std::istream& operator>>(std::istream& input, std::pair<T, T>& data) {
  input >> data.first >> data.second;
  return input;
}
template <typename T>
std::istream& operator>>(std::istream& input, std::vector<T>& data) {
  for (T& first : data) input >> first;
  return input;
}
template <typename T>
std::ostream& operator<<(std::ostream& output, const pair<T, T>& data) {
  output << "(" << data.first << "," << data.second << ")";
  return output;
}
template <typename T>
std::ostream& operator<<(std::ostream& output, const std::vector<T>& data) {
  for (const T& first : data) output << first << " ";
  return output;
}
long long div_up(long long a, long long b) {
  return a / b + ((a ^ b) > 0 && a % b);
}
long long div_down(long long a, long long b) {
  return a / b - ((a ^ b) < 0 && a % b);
}
long long math_mod(long long a, long long b) { return a - b * div_down(a, b); }
template <class T>
using V = vector<T>;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
long long gcd(long long a, long long b) {
  while (b) {
    tie(a, b) = make_pair(b, a % b);
  }
  return a;
}
long long Bit(long long mask, long long bit) { return (mask >> bit) & 1; }
template <long long MOD, long long RT>
struct mint {
  static const long long mod = MOD;
  static constexpr mint rt() { return RT; }
  long long v;
  explicit operator long long() const { return v; }
  mint() { v = 0; }
  mint(long long _v) {
    v = (long long)((-MOD < _v && _v < MOD) ? _v : _v % MOD);
    if (v < 0) v += MOD;
  }
  friend bool operator==(const mint& a, const mint& b) { return a.v == b.v; }
  friend bool operator!=(const mint& a, const mint& b) { return !(a == b); }
  friend bool operator<(const mint& a, const mint& b) { return a.v < b.v; }
  friend string ts(mint a) { return to_string(a.v); }
  mint& operator+=(const mint& m) {
    if ((v += m.v) >= MOD) v -= MOD;
    return *this;
  }
  mint& operator-=(const mint& m) {
    if ((v -= m.v) < 0) v += MOD;
    return *this;
  }
  mint& operator*=(const mint& m) {
    v = (long long)((long long)v * m.v % MOD);
    return *this;
  }
  mint& operator/=(const mint& m) { return (*this) *= inv(m); }
  friend mint pow(mint a, long long p) {
    mint ans = 1;
    assert(p >= 0);
    for (; p; p /= 2, a *= a)
      if (p & 1) ans *= a;
    return ans;
  }
  mint& operator^=(const long long& p) { return (*this) = pow(this, p); }
  friend mint inv(const mint& a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
  }
  mint operator-() const { return mint(-v); }
  mint& operator++() { return *this += 1; }
  mint& operator--() { return *this -= 1; }
  friend mint operator+(mint a, const mint& b) { return a += b; }
  friend mint operator-(mint a, const mint& b) { return a -= b; }
  friend mint operator*(mint a, const mint& b) { return a *= b; }
  friend mint operator/(mint a, const mint& b) { return a /= b; }
  friend mint operator^(mint a, const long long p) { return pow(a, p); }
};
const long long MOD = 1e9 + 7;
typedef mint<MOD, 5> mi;
std::ostream& operator<<(std::ostream& o, const mi& a) {
  cout << a.v;
  return o;
}
vector<vector<mi> > scmb;
void genComb(long long SZ) {
  scmb.assign(SZ, vector<mi>(SZ));
  scmb[0][0] = 1;
  for (long long i = (1); i < (SZ); ++i)
    for (long long j = (0); j < (i + 1); ++j)
      scmb[i][j] = scmb[i - 1][j] + (j ? scmb[i - 1][j - 1] : 0);
}
vector<mi> invs, fac, ifac;
void genFac(long long SZ) {
  invs.resize(SZ), fac.resize(SZ), ifac.resize(SZ);
  invs[1] = fac[0] = ifac[0] = 1;
  for (long long i = (2); i < (SZ); ++i)
    invs[i] = mi(-(long long)MOD / i * (long long)invs[MOD % i]);
  for (long long i = (1); i < (SZ); ++i) {
    fac[i] = fac[i - 1] * i;
    ifac[i] = ifac[i - 1] * invs[i];
  }
}
mi comb(long long a, long long b) {
  if (a < b || b < 0) return 0;
  assert(a < fac.size());
  return fac[a] * ifac[b] * ifac[a - b];
}
const long long N = 3e6 + 7;
void sol() {
  long long k, n;
  cin >> n >> k;
  vector<vector<long long> > w(n + 3);
  long long a, b;
  for (long long i = 0; i < n - 1; i++) {
    cin >> a >> b;
    w[a - 1].push_back(b - 1);
    w[b - 1].push_back(a - 1);
  }
  if (k == 2) {
    cout << n * (n - 1) / 2 << "\n";
    return;
  }
  mi ans = 0;
  for (long long i = 0; i < n; i++) {
    vector<long long> dist(n, -1);
    dist[i] = 0;
    vector<long long> subtree(n, -1);
    subtree[i] = i + 1;
    deque<long long> q;
    q.push_back(i);
    while (q.size() != 0) {
      long long ver = q.front();
      q.pop_front();
      for (auto to : w[ver]) {
        if (dist[to] == -1) {
          dist[to] = 1 + dist[ver];
          q.push_back(to);
          if (ver == i)
            subtree[to] = to + 1;
          else
            subtree[to] = subtree[ver];
        }
      }
    }
    vector<vector<long long> > dist_subtree(n, vector<long long>(n + 1));
    for (long long i = 0; i < n; i++) {
      dist_subtree[dist[i]][subtree[i]]++;
    }
    for (long long loc_dist = 1; loc_dist < n; loc_dist++) {
      vector<mi> X(n + 1);
      X[0] = 1;
      vector<mi> Y(n + 1);
      vector<mi> deg(n);
      for (long long i = 0; i < n; i++) {
        deg[i] = dist_subtree[loc_dist][i];
      }
      for (long long l = 1; l <= n; l++) {
        for (auto el : deg) Y[l] += el;
        mi sign_ = 1;
        mi sum = 0;
        for (long long j = l - 1; j >= 0; j--) {
          sum += sign_ * X[j] * Y[l - j];
          sign_ = -sign_;
        }
        X[l] = sum / mi(l);
        for (long long i = 0; i < n; i++) {
          deg[i] *= dist_subtree[loc_dist][i];
        }
      }
      ans += X[k];
    }
  }
  cout << ans << "\n";
}
void FastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
signed main() {
  genFac(N);
  FastIO();
  long long tst;
  cin >> tst;
  while (tst--) {
    sol();
  }
  return 0;
}
