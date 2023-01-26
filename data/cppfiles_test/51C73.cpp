#include <bits/stdc++.h>
using namespace std;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
void _print(int x) { cerr << x; }
void _print(long x) { cerr << x; }
void _print(long long x) { cerr << x; }
void _print(unsigned x) { cerr << x; }
void _print(unsigned long x) { cerr << x; }
void _print(unsigned long long x) { cerr << x; }
void _print(float x) { cerr << x; }
void _print(double x) { cerr << x; }
void _print(long double x) { cerr << x; }
void _print(char x) { cerr << '\'' << x << '\''; }
void _print(const char* x) { cerr << '\"' << x << '\"'; }
void _print(const string& x) { cerr << '\"' << x << '\"'; }
void _print(bool x) { cerr << (x ? "true" : "false"); }
template <typename A, typename B>
void _print(const pair<A, B>& p);
template <typename A, typename B, typename C>
void _print(const tuple<A, B, C>& tp);
template <typename A, typename B, typename C, typename D>
void _print(const tuple<A, B, C, D>& tp);
template <typename A>
void _print(const A& x);
template <class A, class B, class C>
istream& operator>>(istream& in, tuple<A, B, C>& tp) {
  return in >> get<0>(tp) >> get<1>(tp) >> get<2>(tp);
}
template <class A, class B>
istream& operator>>(istream& in, pair<A, B>& p) {
  return in >> p.first >> p.second;
}
template <class A>
istream& operator>>(istream& in, vector<A>& x) {
  for (A& i : x) in >> i;
  return in;
}
template <typename A, typename B>
void _print(const pair<A, B>& p) {
  cerr << "(";
  _print(p.first);
  cerr << ", ";
  _print(p.second);
  cerr << ')';
}
template <typename A, typename B, typename C>
void _print(const tuple<A, B, C>& tp) {
  cerr << "(";
  _print(get<0>(tp));
  cerr << ", ";
  _print(get<1>(tp));
  cerr << ", ";
  _print(get<2>(tp));
  cerr << ')';
}
template <typename A, typename B, typename C, typename D>
void _print(const tuple<A, B, C, D>& tp) {
  cerr << "(";
  _print(get<0>(tp));
  cerr << ", ";
  _print(get<1>(tp));
  cerr << ", ";
  _print(get<2>(tp));
  cerr << ", ";
  _print(get<3>(tp));
  cerr << ')';
}
template <typename A>
void _print(const A& x) {
  int f = 0;
  cerr << '{';
  for (auto i : x) cerr << (f++ ? ", " : ""), _print(i);
  cerr << "}";
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << " ";
  _print(H);
  dbg_out(T...);
}
const int MOD = 1e9 + 7;
const char nl = '\n';
const long long INF = 1e18;
const int MX = 2e5 + 5;
void solve() {
  long long n;
  cin >> n;
  cout << -(n - 1) << ' ' << n << nl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
