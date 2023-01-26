#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")
using namespace std;
mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
void flush() { cout << flush; }
void flushln() { cout << endl; }
void println() { cout << '\n'; }
template <class T>
void print(const T &x) {
  cout << x;
}
template <class T>
void read(T &x) {
  cin >> x;
}
template <class T, class... U>
void read(T &x, U &...u) {
  read(x);
  read(u...);
}
template <class T, class... U>
void print(const T &x, const U &...u) {
  print(x);
  print(u...);
}
template <class T, class... U>
void println(const T &x, const U &...u) {
  print(x);
  println(u...);
}
template <class T, class U>
inline bool chmin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool chmax(T &x, const U &y) {
  return y > x ? x = y, 1 : 0;
}
template <class T>
inline void sort(T &a) {
  sort((a).begin(), (a).end());
}
template <class T>
inline void rsort(T &a) {
  sort((a).rbegin(), (a).rend());
}
template <class T>
inline void reverse(T &a) {
  reverse((a).begin(), (a).end());
}
template <class T, class U>
inline istream &operator>>(istream &str, pair<T, U> &p) {
  return str >> p.first >> p.second;
}
template <class T>
inline istream &operator>>(istream &str, vector<T> &a) {
  for (auto &i : a) str >> i;
  return str;
}
template <class T>
inline T sorted(T a) {
  sort(a);
  return a;
}
void solve() {
  int n;
  read(n);
  string second, t;
  read(second, t);
  vector<int> dp(1 << 3, -1000000007);
  dp[0] = 0;
  auto getmex = [](int x) { return __builtin_ctz(x + 1); };
  for (int i = 0; i < n; ++i) {
    vector<int> newdp(1 << 3, -1000000007);
    int vs = second[i] - '0';
    int vt = t[i] - '0';
    for (int was = 0; was < (1 << 3); ++was) {
      chmax(newdp[was | (1 << vs) | (1 << vt)], dp[was]);
      chmax(newdp[(1 << vs) | (1 << vt)], dp[was] + getmex(was));
    }
    dp = move(newdp);
  }
  int ans = -1000000007;
  for (int i = 0; i < (1 << 3); ++i) chmax(ans, dp[i] + getmex(i));
  println(ans);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(12);
  int t;
  read(t);
  while (t--) solve();
  return 0;
}
