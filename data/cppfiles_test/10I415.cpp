#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const char& ch) { return "'" + string(1, ch) + "'"; }
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
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
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}
template <typename T>
using vv = vector<vector<T>>;
template <typename T>
using mxpq = priority_queue<T>;
template <typename T>
using mnpq = priority_queue<T, vector<T>, greater<T>>;
template <class A, size_t S>
istream& operator>>(istream& in, array<A, S>& a) {
  for (A& x : a) in >> x;
  return in;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& a) {
  for (T& x : a) in >> x;
  return in;
}
template <class A, size_t S>
ostream& operator<<(ostream& out, array<A, S>& a) {
  bool f = false;
  for (A& x : a) {
    if (f) out << " ";
    out << x;
    f = true;
  }
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& a) {
  bool f = false;
  for (T& x : a) {
    if (f) out << " ";
    out << x;
    f = true;
  }
  return out;
}
template <typename T, typename T1, typename... Tail>
T amin(T& a, T1 b, Tail... c) {
  if (b < a) a = b;
  if constexpr (sizeof...(c) != 0) {
    amin(a, c...);
  }
  return a;
}
template <typename T, typename T1, typename... Tail>
T amax(T& a, T1 b, Tail... c) {
  if (b > a) a = b;
  if constexpr (sizeof...(c) != 0) {
    amax(a, c...);
  }
  return a;
}
int64_t power(int64_t x, int64_t y, int64_t M = 0) {
  int64_t v = 1;
  if (M > int64_t(0)) {
    x = x % M;
    while (y > 0) {
      if (y & 1) v = (v * x) % M;
      y = y >> 1;
      x = (x * x) % M;
    }
    return v;
  } else {
    while (y > 0) {
      if (y & 1) v = v * x;
      y = y >> 1;
      x = x * x;
    }
    return v;
  }
}
int largest_bit(long long x) { return x == 0 ? -1 : 63 - __builtin_clzll(x); }
const long double PI = acos(-1);
const int64_t INF = 0x3f3f3f3f3f3f3f3fll;
const int64_t mod = 1e9 + 7;
const int64_t maxN = 1e6 + 5;
void preSolve(int& testcases) { cin >> testcases; }
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), ans(n, 0);
  map<int, vector<int>> mp;
  map<int, bool> used;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]].push_back(i);
    used[a[i]] = false;
  }
  int cc = 0;
  for (auto& i : mp) {
    if (int(i.second.size()) >= k) {
      cc++;
      int c = k;
      used[i.first] = true;
      while (c--) {
        ans[i.second.back()] = c + 1;
        i.second.pop_back();
      }
    }
  }
  int col = k;
  if (int(mp.size()) - cc >= k) {
    for (auto& i : mp) {
      if (used[i.first]) continue;
      ans[i.second.back()] = col;
      col--;
    }
  }
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
  cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int testcases = 1;
  preSolve(testcases);
  for (int caseno = 1; caseno <= testcases; ++caseno) {
    solve();
  }
  return 0;
}
