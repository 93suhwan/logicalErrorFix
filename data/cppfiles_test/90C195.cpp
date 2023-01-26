#include <bits/stdc++.h>
using namespace std;
template <typename T, size_t N>
long long SIZE(const T (&t)[N]) {
  return N;
}
template <typename T>
long long SIZE(const T &t) {
  return t.size();
}
string to_string(const string s, long long x1 = 0, long long x2 = 1e9) {
  return '"' + ((x1 < s.size()) ? s.substr(x1, x2 - x1 + 1) : "") + '"';
}
string to_string(const char *s) { return to_string((string)s); }
string to_string(const bool b) { return (b ? "true" : "false"); }
string to_string(const char c) { return string({c}); }
template <size_t N>
string to_string(const bitset<N> &b, long long x1 = 0, long long x2 = 1e9) {
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
string to_string(const pair<A, B> &p) {
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
  if (l_v_l_v_l == 0) res += "\n";
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
        res += "\n";
        t_a_b_s = l_v_l_v_l;
      };
    } else {
      t_a_b_s = 0;
    }
    res += to_string(*e, coords...);
    l_v_l_v_l--;
  }
  res += "]";
  if (l_v_l_v_l == 0) res += "\n";
  return res;
}
void dbgm() { ; }
template <typename Heads, typename... Tails>
void dbgm(Heads H, Tails... T) {
  cerr << to_string(H) << " | ";
  dbgm(T...);
}
void FIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const long long N = 2e5 + 6;
int32_t main() {
  FIO();
  long long tc;
  cin >> tc;
  while (tc--) {
    long long x, y;
    cin >> x >> y;
    long long n = x;
    if (x == y)
      n = x;
    else if (x > y) {
      n = x * y + y;
    } else {
      long long r = y % x;
      n = y - r / 2;
    }
    assert(n <= (long long)2e18 and (n % x == y % n));
    cout << n << '\n';
  }
  return 0;
}
