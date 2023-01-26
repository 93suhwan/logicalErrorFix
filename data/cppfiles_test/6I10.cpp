#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;
#define fst first
#define snd second

using UINT = unsigned long long;
using ull = unsigned long long;
template <UINT MD>
struct ModInt {
  using M = ModInt;
  static constexpr UINT get_mod() { return MD; }
  const static M G;
  UINT v;
  ModInt(ll _v = 0) { set_v(UINT(_v % MD + MD)); }
  M &set_v(UINT _v) {
    v = (_v < MD) ? _v : _v - MD;
    return *this;
  }
  explicit operator bool() const { return v != 0; }
  M operator-() const { return M() - *this; }
  M operator+(const M &r) const { return M().set_v(v + r.v); }
  M operator-(const M &r) const { return M().set_v(v + MD - r.v); }
  M operator*(const M &r) const { return M().set_v(UINT(ull(v) * r.v % MD)); }
  M operator/(const M &r) const { return *this * r.inv(); }
  M &operator+=(const M &r) { return *this = *this + r; }
  M &operator-=(const M &r) { return *this = *this - r; }
  M &operator*=(const M &r) { return *this = *this * r; }
  M &operator/=(const M &r) { return *this = *this / r; }
  bool operator==(const M &r) const { return v == r.v; }
  M pow(ll n) const {
    M x = *this, r = 1;
    while (n) {
      if (n & 1) r *= x;
      x *= x;
      n >>= 1;
    }
    return r;
  }
  M inv() const { return pow(MD - 2); }
  friend ostream &operator<<(ostream &os, const M &r) { return os << r.v; }
};
using Mint = ModInt<1000'000'007>;

const int N = 1e5 + 5;
int pr[N], phi[N];

void prec() {
  phi[1] = 1;
  for (int i = 2; i < N; i++) {
    if (pr[i] == 0) {
      phi[i] = i - 1;
      for (int j = i; j < N; j += i)
        pr[j] = i;
    } else {
      int x = i / pr[i];
      phi[i] = phi[x] * (pr[i] - (x % pr[i] != 0));
    }
  }
}

void factorize(int v, VI &facs) {
  for (int x = 1; x * x <= v; x++)
    if (v % x == 0) {
      facs.push_back(x);
      if (x * x != v) facs.push_back(v / x);
    }
  sort(facs.begin(), facs.end());
}

int a[N];
VI facs[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int x = 1; x <= n; x++)
    factorize(x, facs[x]);
  Mint ans(0);
  for (int x = 1; x <= n; x++) {
    VI cfacs;
    Mint term;
    map<int, int> freq;
    for (int i = 1; i <= n / x; i++) {
      for (int y : facs[a[i * x]]) {
        freq[y]++;
      }
    }
    for (auto [y, fy] : freq) {
      term += Mint(phi[y] * 1ll * fy * 1ll * fy);
    }
    ans += term * phi[x];
  }
  cout << ans << '\n';
}

// #define TEST_CASES
// #define PRINT_CASE_NUMBERS

/*----- TEMPLATE ----------------------------------------------------------*/
int main(int argc, char *argv[]) {
#ifdef LOCAL_EXEC
  if (!(argc == 2 && string(argv[1]) == "-c")) {
    freopen("sample.in", "r", stdin);
    freopen("sample.out", "w", stdout);
  }
#else
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#endif

  prec();

  int t = 1;
#ifdef TEST_CASES
  cin >> t;
#endif
  for (int it = 1; it <= t; it++) {
#ifdef PRINT_CASE_NUMBERS
    cout << "Case #" << it << ": ";
#endif
    solve();
  }

  return 0;
}
