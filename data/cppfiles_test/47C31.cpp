#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p, int lvl = 0);
template <typename A>
string to_string(vector<vector<A>> v, int lvl = 0);
template <typename A, typename B>
string to_string(map<A, B> mp, int lvl = 0);
string to_string(const char& ch, int lvl = 0) {
  return "'" + string(1, ch) + "'";
}
string to_string(const string& s, int lvl = 0) { return '"' + s + '"'; }
string to_string(const char* s, int lvl = 0) { return to_string((string)s); }
string to_string(bool b, int lvl = 0) { return (b ? "true" : "false"); }
string to_string(vector<bool> v, int lvl = 0) {
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
string to_string(A v, int lvl = 0) {
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
string to_string(pair<A, B> p, int lvl) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B>
string to_string(map<A, B> mp, int lvl) {
  string res = "{\n", t = string(2 * lvl, ' ');
  for (const auto& x : mp) {
    res += t + to_string(x.first) + ": " + to_string(x.second, lvl + 1) + '\n';
  }
  res += "}";
  return res;
}
template <typename A>
string to_string(vector<vector<A>> v, int lvl) {
  string res = "{\n", t = string(2 * lvl, ' ');
  int _ = 0;
  for (const auto& x : v) {
    res += t + to_string(_++) + ": " + to_string(x, lvl + 1) + '\n';
  }
  res += "}";
  return res;
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
template <typename T>
T amin(T& a) {
  return a;
}
template <typename T>
T amax(T& a) {
  return a;
}
template <typename T, typename T1, typename... Tail>
T amin(T& a, T1 b, Tail... c) {
  if (b < a) a = b;
  amin(a, c...);
  return a;
}
template <typename T, typename T1, typename... Tail>
T amax(T& a, T1 b, Tail... c) {
  if (b > a) a = b;
  amax(a, c...);
  return a;
}
const int64_t mod = 1e9 + 7;
int64_t power(int64_t x, int64_t y, int64_t M = mod) {
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
const int64_t maxN = 2e5 + 5;
void preSolve(int& testcases) { cin >> testcases; }
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int64_t> a(n);
  vector<int64_t> pos, neg;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  pos.push_back(0);
  for (int i = 0; i < n; i++) {
    if (a[i] > 0) {
      pos.push_back(a[i]);
    } else if (a[i] < 0) {
      neg.push_back(abs(a[i]));
    }
  }
  neg.push_back(0);
  reverse(pos.begin(), pos.end());
  42;
  42;
  int64_t multiplier = 1;
  int64_t left = 0, right = 0;
  for (int i = 0; i < pos.size();) {
    left += multiplier * pos[i];
    int j = min<int64_t>(i + k, pos.size());
    if (j == pos.size()) {
      break;
    }
    i = j;
    if (multiplier == 1) {
      multiplier = 2;
    }
  }
  swap(pos, neg);
  multiplier = 2;
  for (int i = 0; i < pos.size();) {
    left += multiplier * pos[i];
    int j = min<int64_t>(i + k, pos.size());
    if (j == pos.size()) {
      break;
    }
    i = j;
  }
  swap(pos, neg);
  multiplier = 2;
  for (int i = 0; i < pos.size();) {
    right += multiplier * pos[i];
    int j = min<int64_t>(i + k, pos.size());
    if (j == pos.size()) {
      break;
    }
    i = j;
  }
  multiplier = 1;
  swap(pos, neg);
  for (int i = 0; i < pos.size();) {
    right += multiplier * pos[i];
    int j = min<int64_t>(i + k, pos.size());
    if (j == pos.size()) {
      break;
    }
    if (multiplier == 1) {
      multiplier = 2;
    }
    i = j;
  }
  42;
  cout << min(left, right) << '\n';
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
