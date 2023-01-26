#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << ' ' << *it << " = " << a;
  err(++it, args...);
}
inline void op() { cout << '\n'; }
template <typename T, typename... Types>
inline void op(T var1, Types... var2) {
  cout << var1 << ' ';
  op(var2...);
}
inline void ip() {}
template <typename T, typename... Types>
inline void ip(T& var1, Types&... var2) {
  cin >> var1;
  ip(var2...);
}
template <typename T, typename U>
inline void min_self(T& x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void max_self(T& x, U y) {
  if (x < y) x = y;
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> pair) {
  return out << "(" << pair.first << ", " << pair.second << ")";
}
template <class T>
ostream& operator<<(ostream& out, vector<T> vec) {
  out << "(";
  for (auto& v : vec) out << v << ' ';
  return out << ")";
}
template <class T>
ostream& operator<<(ostream& out, set<T> vec) {
  out << "(";
  for (auto& v : vec) out << v << ", ";
  return out << ")";
}
template <class L, class R>
ostream& operator<<(ostream& out, map<L, R> vec) {
  out << "(";
  for (auto& v : vec) out << "[" << v.first << ", " << v.second << "]";
  return out << ")";
}
template <class A, class B>
istream& operator>>(istream& in, pair<A, B>& a) {
  return in >> a.first >> a.second;
}
template <class A>
istream& operator>>(istream& in, vector<A>& a) {
  for (A& i : a) in >> i;
  return in;
}
template <class Container>
void split(const std::string& str, Container& cont, char delim = ',') {
  stringstream ss(str);
  string token;
  while (std::getline(ss, token, delim)) {
    cont.push_back(token);
  }
}
long long px[4] = {-1, 0, 1, 0};
long long py[4] = {0, -1, 0, 1};
const long long bigmod = 9999999999971LL;
struct edge {
  long long u, v, wt;
  edge(long long a = 0, long long b = 0, long long c = 0) : u(a), v(b), wt(c) {}
  bool operator<(edge const& other) { return wt < other.wt; }
  friend istream& operator>>(istream& in, edge& x) {
    return in >> x.u >> x.v >> x.wt;
  }
  friend ostream& operator<<(ostream& out, const edge& x) {
    return out << "(" << x.u << ", " << x.v << ", " << x.wt << ")";
  }
};
void abcd() {
  long long n, q;
  ip(n, q);
  string s;
  ip(s);
  vector<long long> a(n + 1), b(n + 1), c(n + 1);
  for (long long i = 0; i <= n - 1; i++) {
    if (s[i] == '+')
      a[i]++;
    else
      a[i]--;
    if (i & 1) {
      b[i + 1] = b[i] - a[i];
      c[i + 1] = c[i] + a[i];
    } else {
      b[i + 1] = b[i] + a[i];
      c[i + 1] = c[i] - a[i];
    }
  }
  while (q--) {
    long long lx, rx;
    ip(lx, rx);
    lx--;
    rx--;
    if ((rx - lx + 1) & 1)
      op(1);
    else {
      long long sum = 0;
      if (rx & 1)
        sum = b[rx + 1] - b[lx];
      else
        sum = c[rx + 1] - c[lx];
      if (sum == 0)
        op(0);
      else
        op(2);
    }
  }
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long T = 1;
  cin >> T;
  while (T--) {
    abcd();
  }
  return 0;
}
