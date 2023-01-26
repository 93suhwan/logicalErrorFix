#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T, size_t N>
long long SIZE(const T (&t)[N]) {
  return N;
}
template <typename T>
long long SIZE(const T& t) {
  return t.size();
}
string to_string(const string s, long long x1 = 0, long long x2 = 1e9) {
  return '"' + ((x1 < s.size()) ? s.substr(x1, x2 - x1 + 1) : "") + '"';
}
string to_string(const char* s) { return to_string((string)s); }
string to_string(const bool b) { return (b ? "true" : "false"); }
string to_string(const char c) { return string({c}); }
template <size_t N>
string to_string(const bitset<N>& b, long long x1 = 0, long long x2 = 1e9) {
  string t = "";
  for (long long __iii__ = min(x1, SIZE(b)), __jjj__ = min(x2, SIZE(b) - 1);
       __iii__ <= __jjj__; ++__iii__) {
    t += b[__iii__] + '0';
  }
  return '"' + t + '"';
}
template <typename A, typename... C>
string to_string(const A(&v), long long x1 = 0, long long x2 = 1e9,
                 C... coords);
long long l_v_l_v_l = 0, t_a_b_s = 0;
template <typename A, typename B>
string to_string(const pair<A, B>& p) {
  l_v_l_v_l++;
  string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
  l_v_l_v_l--;
  return res;
}
template <typename A, typename... C>
string to_string(const A(&v), long long x1, long long x2, C... coords) {
  long long rnk = rank<A>::value;
  string tab(t_a_b_s, ' ');
  string res = "";
  bool first = true;
  if (l_v_l_v_l == 0) res += '\n';
  res += tab + "[";
  x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v));
  auto l = begin(v);
  advance(l, x1);
  auto r = l;
  advance(r, (x2 - x1) + (x2 < SIZE(v)));
  for (auto e = l; e != r; e = next(e)) {
    if (!first) {
      res += ", ";
    }
    first = false;
    l_v_l_v_l++;
    if (e != l) {
      if (rnk > 1) {
        res += '\n';
        t_a_b_s = l_v_l_v_l;
      };
    } else {
      t_a_b_s = 0;
    }
    res += to_string(*e, coords...);
    l_v_l_v_l--;
  }
  res += "]";
  if (l_v_l_v_l == 0) res += '\n';
  return res;
}
void dbgm() { ; }
template <typename Heads, typename... Tails>
void dbgm(Heads H, Tails... T) {
  cout << to_string(H) << " | ";
  dbgm(T...);
}
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
const long long inf = 1e9, MX = 2e5 + 1;
const long long md = 1e9 + 7;
vector<long long> fac(MX);
long long be(long long b, long long e) {
  long long ans = 1;
  while (e) {
    if (e & 1) ans *= b;
    e /= 2;
    b *= b;
    ans %= md;
    b %= md;
  }
  return ans;
}
long long C(long long n, long long r) {
  return (((fac[n] * be(fac[r], md - 2)) % md) * be(fac[n - r], md - 2)) % md;
}
void solve() {
  long long n;
  cin >> n;
  long long ans = fac[n * 2];
  ans *= be(2, md - 2);
  ans %= md;
  cout << ans;
  return;
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  fac[0] = 1;
  for (long long i = 1; i < MX; i++) fac[i] = fac[i - 1] * i, fac[i] %= md;
  long long T = 1;
  cin >> T;
  while (T--) {
    solve();
    cout << '\n';
  }
  return 0;
}
