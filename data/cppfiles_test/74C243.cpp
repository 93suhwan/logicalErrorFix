#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
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
long long msb(long long x);
long long lsb(long long x);
vector<long long> tovec(string a);
string tostr(vector<long long> a);
const long long md = 1e9 + 7, MX = 500001;
long long get(long long n, long long a, long long b, long long colored) {
  if (colored > a) return -1;
  long long even = (n + 1) / 2;
  long long odd = n / 2;
  if (colored > even) return -1;
  if (even - colored > b) return -1;
  return even - colored + a - colored;
}
void solve() {
  long long a, b;
  cin >> a >> b;
  set<long long> s;
  for (long long i = 0; i <= a; i++) {
    long long x = get(a + b, a, b, i);
    if (x != -1) s.insert(x);
  }
  for (long long i = 0; i <= b; i++) {
    long long x = get(a + b, b, a, i);
    if (x != -1) s.insert(x);
  }
  cout << s.size() << '\n';
  for (long long x : s) cout << x << " ";
  return;
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  long long T = 1;
  cin >> T;
  while (T--) {
    solve();
    if (T) cout << '\n';
  }
  return 0;
}
long long msb(long long x) {
  for (long long i = 60; i > -1; i--)
    if ((1LL << i) & x) return i;
  return -1;
}
long long lsb(long long x) {
  for (long long i = 0; i < 61; i++)
    if ((1LL << i) & x) return i;
  return -1;
}
vector<long long> tovec(string a) {
  vector<long long> ans;
  for (char x : a) ans.push_back(((long long)(x) - 'a'));
  return ans;
}
string tostr(vector<long long> a) {
  string ans;
  for (long long x : a) ans += ((char)((x) + 'a'));
  return ans;
}
