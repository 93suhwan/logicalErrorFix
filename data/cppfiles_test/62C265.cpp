#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int f = 0;
  cerr << '{';
  for (auto& i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
template <int MOD_>
struct modnum {
  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");

 private:
  using ll = long long;
  int v;
  static int minv(int a, int m) {
    a %= m;
    assert(a);
    return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
  }

 public:
  modnum() : v(0) {}
  modnum(ll v_) : v(int(v_ % MOD)) {
    if (v < 0) v += MOD;
  }
  explicit operator int() const { return v; }
  friend std::ostream& operator<<(std::ostream& out, const modnum& n) {
    return out << int(n);
  }
  friend std::istream& operator>>(std::istream& in, modnum& n) {
    ll v_;
    in >> v_;
    n = modnum(v_);
    return in;
  }
  friend bool operator==(const modnum& a, const modnum& b) {
    return a.v == b.v;
  }
  friend bool operator!=(const modnum& a, const modnum& b) {
    return a.v != b.v;
  }
  modnum inv() const {
    modnum res;
    res.v = minv(v, MOD);
    return res;
  }
  friend modnum inv(const modnum& m) { return m.inv(); }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD - v : 0;
    return res;
  }
  friend modnum neg(const modnum& m) { return m.neg(); }
  modnum operator-() const { return neg(); }
  modnum operator+() const { return modnum(*this); }
  modnum& operator++() {
    v++;
    if (v == MOD) v = 0;
    return *this;
  }
  modnum& operator--() {
    if (v == 0) v = MOD;
    v--;
    return *this;
  }
  modnum& operator+=(const modnum& o) {
    v += o.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  modnum& operator-=(const modnum& o) {
    v -= o.v;
    if (v < 0) v += MOD;
    return *this;
  }
  modnum& operator*=(const modnum& o) {
    v = int(ll(v) * ll(o.v) % MOD);
    return *this;
  }
  modnum& operator/=(const modnum& o) { return *this *= o.inv(); }
  friend modnum operator++(modnum& a, int) {
    modnum r = a;
    ++a;
    return r;
  }
  friend modnum operator--(modnum& a, int) {
    modnum r = a;
    --a;
    return r;
  }
  friend modnum operator+(const modnum& a, const modnum& b) {
    return modnum(a) += b;
  }
  friend modnum operator-(const modnum& a, const modnum& b) {
    return modnum(a) -= b;
  }
  friend modnum operator*(const modnum& a, const modnum& b) {
    return modnum(a) *= b;
  }
  friend modnum operator/(const modnum& a, const modnum& b) {
    return modnum(a) /= b;
  }
};
template <typename T>
T pow(T a, long long b) {
  assert(b >= 0);
  T r = 1;
  while (b) {
    if (b & 1) r *= a;
    b >>= 1;
    a *= a;
  }
  return r;
}
using num = modnum<int(1e9 + 13)>;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int nTest = 1;
  cin >> nTest;
  while (nTest--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (a[n] == 0) {
      for (int i = 1; i <= n + 1; i++) cout << i << " ";
      cout << endl;
      continue;
    }
    if (a[1] == 1) {
      cout << n + 1;
      for (int i = 1; i <= n; i++) cout << " " << i;
      cout << endl;
      continue;
    }
    for (int i = 1; i <= n - 1; i++)
      if (a[i] == 0 && a[i + 1] == 1) {
        for (int j = 1; j <= i; j++) cout << j << " ";
        cout << n + 1;
        for (int j = i + 1; j <= n; j++) cout << " " << j;
        cout << endl;
        goto END;
      }
    cout << -1 << endl;
  END : {}
  }
  return 0;
}
