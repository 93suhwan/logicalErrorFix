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
  long long n;
  ip(n);
  string ori;
  ip(ori);
  string s = ori;
  reverse(s.begin(), s.end());
  long long g[n][n];
  memset(g, 0, sizeof(g));
  for (long long i = 0; i <= n - 1; i++) {
    for (long long j = i + 1; j <= n - 1; j++) {
      g[i][j] = j + 1;
      if (s[i] == s[j]) {
        if (i) g[i][j] = g[i - 1][j - 1] + 1;
      } else if (s[i] > s[j])
        g[i][j] = 1;
      else
        g[i][j] = INT_MIN;
    }
  }
  vector<long long> dp(n);
  long long res = 0;
  for (long long i = 0; i <= n - 1; i++) {
    long long x = dp[i] = i + 1;
    for (long long j = 0; j <= i - 1; j++) {
      if (g[j][i] > 0) {
        long long rem = g[j][i] - 1;
        max_self(dp[i], dp[j] + x - rem);
      }
    }
    max_self(res, dp[i]);
  }
  op(res);
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    abcd();
  }
  return 0;
}
