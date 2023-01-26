#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);
const int di[8] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dj[8] = {1, -1, 0, 0, 1, -1, 1, -1};
long long FirstTrue(long long l, long long r, function<bool(long long)> f) {
  while (l < r) {
    long long mid = l + (r - l) / 2;
    f(mid) ? r = mid : l = mid + 1;
  }
  return l;
}
long long LastTrue(long long l, long long r, function<bool(long long)> f) {
  while (l < r) {
    long long mid = l + (r - l + 1) / 2;
    f(mid) ? l = mid : r = mid - 1;
  }
  return l;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
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
void re(long double& x) {
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
  x = complex<T>(a, b);
}
template <class T1, class T2>
void re(pair<T1, T2>& p) {
  re(p.first, p.second);
}
template <class T>
void re(vector<T>& a) {
  for (int i = (0); i < ((int)a.size()); i += (1)) re(a[i]);
}
template <class T, size_t SZ>
void re(array<T, SZ>& a) {
  for (int i = (0); i < (SZ); i += (1)) re(a[i]);
}
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
  pr(x.first, ' ', x.second);
}
template <class T>
void prContain(const T& x) {
  for (auto& a : x) pr(a, ' ');
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
void ps() { cout << '\n'; }
template <class Arg, class... Args>
void ps(const Arg& first, const Args&... rest) {
  pr(first, " ");
  ps(rest...);
}
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(const char& c) {
  char s[1] = {c};
  return to_string(s);
}
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
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
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
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void DBG() { cerr << "]" << endl; }
template <class H, class... T>
void DBG(H h, T... t) {
  cerr << to_string(h);
  if (sizeof...(t)) cerr << ", ";
  DBG(t...);
}
void Suhaib_Sawalha() {
  int n, m, k;
  re(n, m, k);
  vector<int> x(n), y(m);
  vector<array<int, 2>> a(k);
  re(x, y, a);
  set<int> X, Y;
  for (auto& e : x) X.insert(e);
  for (auto& e : y) Y.insert(e);
  vector<int> hx, hy;
  for (int i = (0); i < (k); i += (1)) {
    if (!Y.count(a[i][1])) hx.push_back(i);
    if (!X.count(a[i][0])) hy.push_back(i);
  }
  map<int, int> mp, mp2;
  long long ans = 0;
  int j = 0;
  sort(hy.begin(), hy.end(), [&](int i, int j) { return a[i][0] < a[j][0]; });
  sort(hx.begin(), hx.end(), [&](int i, int j) { return a[i][1] < a[j][1]; });
  for (int i = (0); i < ((int)hx.size()); i += (1)) {
    if (i) {
      auto it = Y.lower_bound(a[hx[i - 1]][1]);
      if (it != Y.end() && *it <= a[hx[i]][1]) {
        mp.clear();
        j = i;
      }
    }
    ans += i - j - mp[a[hx[i]][0]];
    ++mp[a[hx[i]][0]];
  }
  j = 0;
  for (int i = (0); i < ((int)hy.size()); i += (1)) {
    if (i) {
      auto it = X.lower_bound(a[hy[i - 1]][0]);
      if (it != X.end() && *it <= a[hy[i]][0]) {
        mp2.clear();
        j = i;
      }
    }
    ans += i - j - mp2[a[hy[i]][1]];
    ++mp2[a[hy[i]][1]];
  }
  pr(ans);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int _;
  cin >> _;
  for (int i = 1; i <= _; ++i, cout << '\n') Suhaib_Sawalha();
  return 0;
}
