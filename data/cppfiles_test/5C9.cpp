#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = long double;
using str = string;
using pi = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T, size_t SZ>
using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vpi = V<pi>;
const int MOD = 1e9 + 7;
const db EPS = 1e-9;
const ll BIG = 1e18;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
struct mi {
  int v;
  explicit operator int() const { return v; }
  mi() : v(0) {}
  mi(ll _v) : v(int(_v % MOD)) { v += (v < 0) * MOD; }
};
mi& operator+=(mi& a, mi b) {
  if ((a.v += b.v) >= MOD) a.v -= MOD;
  return a;
}
mi& operator-=(mi& a, mi b) {
  if ((a.v -= b.v) < 0) a.v += MOD;
  return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((ll)a.v * b.v); }
mi& operator*=(mi& a, mi b) { return a = a * b; }
mi pow(mi a, ll p) {
  assert(p >= 0);
  return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
  assert(a.v != 0);
  return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }
bool operator==(mi a, mi b) { return a.v == b.v; }
vector<mi> invs, fac, ifac;
void genFac(int SZ) {
  invs.resize(SZ), fac.resize(SZ), ifac.resize(SZ);
  invs[1] = fac[0] = ifac[0] = 1;
  for (int i = (2); i < (SZ); ++i)
    invs[i] = mi(-(ll)MOD / i * (int)invs[MOD % i]);
  for (int i = (1); i < (SZ); ++i)
    fac[i] = fac[i - 1] * i, ifac[i] = ifac[i - 1] * invs[i];
}
mi comb(int a, int b) {
  if (a < b || b < 0) return 0;
  return fac[a] * ifac[b] * ifac[a - b];
}
const int mx = 100005;
struct Eff {
  int n, k;
  mi first[mx];
  void solve() {
    genFac(100005);
    cin >> n >> k;
    map<int, int> cnt;
    int negs = 0;
    for (int i = 1; i <= n; i++) {
      int A;
      cin >> A;
      if (A == -1) {
        negs++;
      } else {
        cnt[A]++;
      }
    }
    map<int, mi> all_cnts;
    for (auto u : cnt) {
      all_cnts[u.second] = mi(0);
    }
    all_cnts[0] = mi(0);
    first[0] = mi(0);
    for (int i = 0; i <= n - 1; i++) {
      first[i + 1] = mi(-n);
      if (i - 1 >= 0) {
        first[i + 1] -= mi(i) * mi(k - 1) * first[i - 1];
      }
      first[i + 1] += first[i] * (mi(n) - 2 * mi(i) + mi(i) * mi(k));
      first[i + 1] = first[i + 1] / mi(n - i);
    }
    vector<mi> k1pows(n + 1, mi(1));
    for (int i = 1; i <= n; i++) {
      k1pows[i] = k1pows[i - 1] * mi(k - 1);
    }
    for (auto& u : all_cnts) {
      for (int i = 0; i <= negs; i++) {
        u.second += first[u.first + i] * mi(comb(negs, i)) * k1pows[negs - i];
      }
      u.second = u.second / pow(mi(k), negs);
    }
    mi ans = mi(0);
    map<int, int> cnt_cnt;
    for (auto u : cnt) {
      cnt_cnt[u.second]++;
    }
    cnt_cnt[0] += (k - int((cnt).size()));
    for (auto u : cnt_cnt) {
      ans += all_cnts[u.first] * mi(u.second);
    }
    ans -= (first[n] + mi(k - 1) * first[0]);
    cout << ans.v << "\n";
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  Eff e;
  e.solve();
}
