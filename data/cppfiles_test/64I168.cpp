#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ul = unsigned long long;
using db = double;
using pi = pair<int, int>;
using pl = pair<long long, long long>;
using pd = pair<ld, ld>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long long>;
using vd = vector<ld>;
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
template <typename T, size_t size>
using va = vector<array<T, size>>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
namespace input {
template <class T>
void re(complex<T>& x);
template <class T1, class T2>
void re(pair<T1, T2>& p);
template <class T>
void re(vector<T>& a);
template <class T, size_t SZ>
void re(array<T, SZ>& a);
template <class T>
void re(T& x) {
  cin >> x;
}
void re(double& x) {
  string t;
  re(t);
  x = stod(t);
}
void re(ld& x) {
  string t;
  re(t);
  x = stold(t);
}
template <class Arg, class... Args>
void re(Arg& first, Args&... rest) {
  re(first);
  re(rest...);
}
template <class T>
void re(complex<T>& x) {
  T a, b;
  re(a, b);
  x = cd(a, b);
}
template <class T1, class T2>
void re(pair<T1, T2>& p) {
  re(p.first, p.second);
}
template <class T>
void re(vector<T>& a) {
  for (int i = 0; i < int(((int)(a).size())); i++) re(a[i]);
}
template <class T, size_t SZ>
void re(array<T, SZ>& a) {
  for (int i = 0; i < int(SZ); i++) re(a[i]);
}
}  // namespace input
using namespace input;
namespace output {
template <class T1, class T2>
void pr(const pair<T1, T2>& x);
template <class T, size_t SZ>
void pr(const array<T, SZ>& x);
template <class T>
void pr(const vector<T>& x);
template <class T>
void pr(const set<T>& x);
template <class T1, class T2>
void pr(const map<T1, T2>& x);
template <class T>
void pr(const T& x) {
  cout << x;
}
template <class Arg, class... Args>
void pr(const Arg& first, const Args&... rest) {
  pr(first);
  pr(rest...);
}
template <class T1, class T2>
void pr(const pair<T1, T2>& x) {
  pr(x.first, " ", x.second);
}
template <class T>
void prContain(const T& x) {
  bool fst = 1;
  for (const auto& a : x) pr(!fst ? " " : "", a), fst = 0;
}
template <class T, size_t SZ>
void pr(const array<T, SZ>& x) {
  prContain(x);
}
template <class T>
void pr(const vector<T>& x) {
  prContain(x);
}
template <class T>
void pr(const set<T>& x) {
  prContain(x);
}
template <class T1, class T2>
void pr(const map<T1, T2>& x) {
  prContain(x);
}
void ps() { pr("\n"); }
template <class Arg>
void ps(const Arg& first) {
  pr(first);
  ps();
}
template <class Arg, class... Args>
void ps(const Arg& first, const Args&... rest) {
  pr(first, " ");
  ps(rest...);
}
}  // namespace output
using namespace output;
namespace error {
template <class T1, class T2>
void dg(const pair<T1, T2>& x);
template <class T, size_t SZ>
void dg(const array<T, SZ>& x);
template <class T>
void dg(const vector<T>& x);
template <class T>
void dg(const set<T>& x);
template <class T1, class T2>
void dg(const map<T1, T2>& x);
template <class T>
void dg(const T& x) {
  cerr << x;
}
template <class Arg, class... Args>
void dg(const Arg& first, const Args&... rest) {
  dg(first);
  dg(rest...);
}
template <class T1, class T2>
void dg(const pair<T1, T2>& x) {
  dg(x.first, " ", x.second);
}
template <class T>
void dgContain(const T& x) {
  bool fst = 1;
  for (const auto& a : x) dg(!fst ? " " : "", a), fst = 0;
}
template <class T, size_t SZ>
void dg(const array<T, SZ>& x) {
  dgContain(x);
}
template <class T>
void dg(const vector<T>& x) {
  dgContain(x);
}
template <class T>
void dg(const set<T>& x) {
  dgContain(x);
}
template <class T1, class T2>
void dg(const map<T1, T2>& x) {
  dgContain(x);
}
void ds() { dg("\n"); }
template <class Arg>
void ds(const Arg& first) {
  dg(first);
  ds();
}
template <class Arg, class... Args>
void ds(const Arg& first, const Args&... rest) {
  dg(first, " ");
  ds(rest...);
}
}  // namespace error
using namespace error;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
void debug() { cerr << endl; }
template <typename Head, typename... Tail>
void debug(Head H, Tail... T) {
  dg(H);
  debug(T...);
}
inline long long modPow(long long x, long long y, long long mod) {
  long long res = 1;
  x = x % mod;
  ;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % mod;
    }
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
char dirs[4] = {'L', 'D', 'R', 'U'};
unordered_map<char, int> rdirs = {{'R', 2}, {'D', 1}, {'L', 0}, {'U', 3}};
const long long mod = 1e9 + 7;
const long long INF = 2e18 + 6;
const int MXN = 5e5 + 5;
struct Hashvalue {
  long long v1, v2, l;
  Hashvalue(int x = 0, int y = 0, int len = 0) {
    v1 = x;
    v2 = y;
    l = len;
  }
  bool operator==(const Hashvalue& c) { return (v1 == c.v1 && v2 == c.v2); }
};
template <int SZ>
struct StringHash {
  const long long m1 = 8675309, m2 = 1e9 + 7;
  const long long s1 = 10, s2 = 10;
  long long s1Pow[SZ], s2Pow[SZ];
  StringHash() {
    s1Pow[0] = s2Pow[0] = 1;
    for (int i = 1; i < SZ; i++) s1Pow[i] = (s1Pow[i - 1] * s1) % m1;
    for (int i = 1; i < SZ; i++) s2Pow[i] = (s2Pow[i - 1] * s2) % m2;
  }
  Hashvalue add(Hashvalue h, char o) {
    h.v1 = (h.v1 * s1 + (o - '0')) % m1;
    h.v2 = (h.v2 * s2 + (o - '0')) % m2;
    h.l++;
    return h;
  }
  Hashvalue add(Hashvalue h, Hashvalue o) {
    h.v1 = (h.v1 * s1Pow[o.l] + o.v1) % m1;
    h.v2 = (h.v2 * s2Pow[o.l] + o.v2) % m2;
    h.l += o.l;
    return h;
  }
  vector<Hashvalue> getPrefixHashes(string word) {
    int n = word.size();
    vector<Hashvalue> toReturn(n + 1);
    for (int i = 1; i <= n; i++) {
      toReturn[i] = toReturn[i - 1];
      toReturn[i] = add(toReturn[i], word[i - 1]);
    }
    return toReturn;
  }
  Hashvalue substringHash(vector<Hashvalue>& prefixHashes, int from, int to) {
    if (from == to) return Hashvalue(-1, -1, 0);
    Hashvalue old = prefixHashes[to], toSub = prefixHashes[from];
    int diff = to - from;
    old.v1 = (old.v1 - (toSub.v1 * s1Pow[diff]) % m1 + m1) % m1;
    old.v2 = (old.v2 - (toSub.v2 * s2Pow[diff]) % m2 + m2) % m2;
    old.l = to - from;
    return old;
  }
};
StringHash<MXN> sh;
vector<int> z_function(string& second) {
  int n = second.size();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && second[z[i]] == second[i + z[i]]) z[i]++;
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
Hashvalue operator+(Hashvalue a, Hashvalue b) {
  a.v1 = (a.v1 + b.v1) % sh.m1;
  a.v2 = (a.v2 + b.v2) % sh.m2;
  return a;
}
void solve() {
  string second, x;
  re(second, x);
  int n = ((int)(second).size()), m = ((int)(x).size());
  auto prefs = sh.getPrefixHashes(second);
  auto prefx = sh.getPrefixHashes(x);
  for (int i = 0; i + 2 * m - 2 <= n; i++) {
    if (sh.substringHash(prefs, i, i + m - 1) +
            sh.substringHash(prefs, i + m - 1, i + 2 * m - 2) ==
        prefx.back()) {
      ps(i + 1, i + m - 1);
      ps(i + m, i + 2 * m - 2);
      return;
    }
  }
  string ns = x + "#" + second;
  auto p = z_function(ns);
  for (int i = 0; i < n; i++) {
    int lcp = p[m + 1 + i];
    if (i + m + m - lcp <= n &&
        sh.substringHash(prefs, i, i + m) +
                sh.substringHash(prefs, i + m, i + m + m - lcp) ==
            prefx.back()) {
      ps(i + 1, i + m);
      ps(i + m + 1, i + m + m - lcp);
      return;
    }
    if (i + m + m - lcp - 1 <= n &&
        sh.substringHash(prefs, i, i + m) +
                sh.substringHash(prefs, i + m, i + m + (m - lcp - 1)) ==
            prefx.back()) {
      ps(i + 1, i + m);
      ps(i + m + 1, i + m + m - lcp - 1);
      return;
    }
    if (i + m <= n && i - (m - lcp) >= 0 &&
        sh.substringHash(prefs, i, i + m) +
                sh.substringHash(prefs, i - (m - lcp), i) ==
            prefx.back()) {
      ps(i - (m - lcp) + 1, i);
      ps(i + 1, i + m);
      return;
    }
    if (i + m <= n && i - (m - lcp - 1) >= 0 &&
        sh.substringHash(prefs, i, i + m) +
                sh.substringHash(prefs, i - (m - lcp - 1), i) ==
            prefx.back()) {
      ps(i - (m - lcp - 1) + 1, i);
      ps(i + 1, i + m);
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(6);
  int t = 1, tc = 1;
  while (t--) {
    solve();
    tc++;
  }
  return 0;
}
