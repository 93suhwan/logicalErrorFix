#include <bits/stdc++.h>
using namespace std;
string dir = "LRUD";
long long xdir[] = {-1, 1, 0, 0}, ydir[] = {0, 0, -1, 1};
template <typename T, typename U>
inline long long power(T n, U k) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n;
    n = n * n;
  }
  return r;
}
template <typename T, typename U>
inline bool ckmin(T& x, U y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T, typename U>
inline bool ckmax(T& x, U y) {
  return x < y ? x = y, 1 : 0;
}
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void line(long long line) { cerr << "( line: " << line << " ) "; }
void file() {}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  file();
  long long _t;
  cin >> _t;
  for (long long tc = 1; tc <= _t; tc++) {
    long long n;
    cin >> n;
    vector<long long> a(n + 1, 0), b(n + 1, 0);
    set<long long> ans;
    for (long long i = 1; i < n + 1; ++i) {
      long long x;
      cin >> x;
      a[i] = a[i - 1] + x;
    }
    for (long long i = 1; i < n + 1; ++i) {
      long long x;
      cin >> x;
      b[i] = x + b[i - 1];
    };
    for (long long i = 1; i < n + 1; ++i) {
      long long val = max(a[n] - a[i], b[i - 1]);
      ;
      ans.insert(val);
    }
    cout << *ans.begin() << "\n";
  }
  return 0;
}
