#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <class T>
using vt = vector<T>;
template <class T>
using vvt = vt<vt<T>>;
template <class T>
using pr = pair<T, T>;
template <typename T>
istream& operator>>(istream& is, vt<T>& v) {
  const size_t n = v.size();
  for (size_t i = 0; i < n; ++i) is >> v[i];
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, const vt<T>& v) {
  const size_t n = v.size();
  for (size_t i = 0; i < n; ++i) {
    if (i != 0) os << ' ';
    os << v[i];
  }
  return os;
}
template <typename T>
istream& operator>>(istream& is, vvt<T>& vv) {
  const size_t n = vv.size();
  const size_t m = vv[0].size();
  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j < m; ++j) is >> vv[i][j];
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, const vvt<T>& vv) {
  const size_t n = vv.size();
  const size_t m = vv[0].size();
  for (size_t i = 0; i < n; ++i) {
    if (i != 0) os << '\n';
    for (size_t j = 0; j < m; ++j) {
      if (j != 0) os << ' ';
      os << vv[i][j];
    }
  }
  return os;
}
template <typename T, typename U>
istream& operator>>(istream& is, pair<T, U>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << p.first << ' ' << p.second;
  return os;
}
template <class A, class B>
string to_string(pair<A, B> p);
template <class A, class B, class C>
string to_string(tuple<A, B, C> p);
template <class A, class B, class C, class D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(const char& c) { return (string) "" + c; }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) res += ", ";
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
  return res;
}
template <class A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <class A, class B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <class A, class B, class C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <class A, class B, class C, class D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <class Head, class... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
template <class T, class U>
bool chmax(T& a, U b) {
  if (a < b) {
    a = b;
    return true;
  } else
    return false;
}
template <class T, class U>
bool chmin(T& a, U b) {
  if (b < a) {
    a = b;
    return true;
  } else
    return false;
}
int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    ll x, y;
    cin >> x >> y;
    ll n;
    if (x <= y) {
      ll dist = (y - x);
      x += (dist / (2 * x)) * x;
      n = (x + y) / 2;
    } else {
      n = x * y + y;
    }
    cout << n << '\n';
  }
  return 0;
}
