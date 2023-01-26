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
void adebug(int a[], int l, int r) {
  for (int i = l; i <= r; i++) {
    cerr << a[i] << " ";
  }
  cerr << '\n';
}
template <typename T, typename V>
void mdebug(map<T, vector<V>> m) {
  for (auto x : m) {
    cerr << x.first << " : [ ";
    for (auto c : x.second) cerr << c << " ";
    cerr << "]" << '\n';
  }
}
template <class T>
bool umin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool umax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <class A>
void read(vector<A>& v);
template <class A, size_t second>
void read(array<A, second>& a);
template <class T>
void read(T& x) {
  cin >> x;
}
void read(double& d) {
  string t;
  read(t);
  d = stod(t);
}
void read(long double& d) {
  string t;
  read(t);
  d = stold(t);
}
template <class H, class... T>
void read(H& h, T&... t) {
  read(h);
  read(t...);
}
template <class A>
void read(vector<A>& x) {
  for (auto& a : x) read(a);
}
template <class A, size_t second>
void read(array<A, second>& x) {
  for (auto& a : x) read(a);
}
string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(const char* s) { return string(s); }
string to_string(string s) { return s; }
string to_string(vector<bool> v) {
  string res;
  for (int i = (0); ((1) > 0 ? i < ((int)(v).size()) : i > ((int)(v).size()));
       i += (1))
    res += char('0' + v[i]);
  return res;
}
template <size_t second>
string to_string(bitset<second> b) {
  string res;
  for (int i = (0); ((1) > 0 ? i < (second) : i > (second)); i += (1))
    res += char('0' + b[i]);
  return res;
}
template <class T>
string to_string(T v) {
  bool f = 1;
  string res;
  for (auto& x : v) {
    if (!f) res += ' ';
    f = 0;
    res += to_string(x);
  }
  return res;
}
template <class A>
void pff(A x) {
  cout << to_string(x);
}
template <class H, class... T>
void pff(const H& h, const T&... t) {
  pff(h);
  pff(t...);
}
void print() { pff("\n"); }
template <class H, class... T>
void print(const H& h, const T&... t) {
  pff(h);
  if (sizeof...(t)) pff(' ');
  print(t...);
}
struct PH {
  size_t operator()(const pair<int, int>& x) const {
    size_t ans = 0;
    for (int i = 0; i < x.first; i++) ans += x.second;
    return ans;
  }
};
template <class T>
void offset(long long o, T& x) {
  x += o;
}
template <class T>
void offset(long long o, vector<T>& x) {
  for (auto& a : x) offset(o, a);
}
template <class T, size_t second>
void offset(long long o, array<T, second>& x) {
  for (auto& a : x) offset(o, a);
}
template <class T>
void fk(T a) {
  print(a);
  exit(0);
}
long const M = 1e9 + 7;
const long long INF = 1e18;
const long long mxN = 1e6, di[4] = {1, 0, -1, 0}, dj[4] = {0, -1, 0, 1};
void solve() {
  string s;
  read(s);
  long long n = (long long)(s).size();
  vector<long long> c(26), p(26);
  for (auto& x : s) c[x - 'a']++;
  string ans;
  for (long long i = (0); ((1) > 0 ? i < (n) : i > (n)); i += (1)) {
    p[s[i] - 'a']++;
    vector<long long> a;
    bool ok = 1;
    for (long long j = (0); ((1) > 0 ? j < (26) : j > (26)); j += (1)) {
      if (!c[j]) continue;
      if (!p[j] || c[j] % p[j]) {
        ok = 0;
        continue;
      }
      a.push_back(c[j] / p[j]);
    }
    if (!ok) continue;
    sort((a).begin(), (a).end());
    for (long long j = (0);
         ((1) > 0 ? j < ((long long)(a).size()) : j > ((long long)(a).size()));
         j += (1))
      if (a[j] != j + 1) ok = 0;
    if (!ok) continue;
    vector<long long> b;
    for (long long j = (0); ((1) > 0 ? j < (26) : j > (26)); j += (1)) {
      if (!c[j]) continue;
      b.push_back(j);
    }
    sort((b).begin(), (b).end(), [&](const long long& x, const long long& y) {
      return c[x] / p[x] < c[y] / p[y];
    });
    ans = s.substr(0, i + 1);
    string t;
    for (auto& x : b) t += 'a' + x;
    string d = ans, tt;
    ;
    for (long long j = (0);
         ((1) > 0 ? j < ((long long)(b).size()) : j > ((long long)(b).size()));
         j += (1)) {
      tt += d;
      char y = ('a' + b[j]);
      string dd;
      for (long long k = (0); ((1) > 0 ? k < ((long long)(d).size())
                                       : k > ((long long)(d).size()));
           k += (1)) {
        if (d[k] == y) continue;
        dd += d[k];
      };
      d = dd;
    };
    ;
    if (tt != s) return print("-1");
    print(ans, t);
    return;
  }
  return print("-1");
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T = 1;
  read(T);
  for (long long _ = (0); ((1) > 0 ? _ < (T) : _ > (T)); _ += (1)) {
    solve();
  }
  return 0;
}
