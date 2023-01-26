#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9 + 7;
template <typename T1, typename T2>
istream &operator>>(istream &istream, pair<T1, T2> &p) {
  return (istream >> p.first >> p.second);
}
template <typename T>
istream &operator>>(istream &istream, vector<T> &v) {
  for (auto &it : v) cin >> it;
  return istream;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) {
  return (ostream << p.first << " " << p.second);
}
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
  for (auto &it : c) cout << it << " ";
  return ostream;
}
template <typename T>
void print(T &&t) {
  cout << t << "\n";
}
template <typename T, typename... Args>
void print(T &&t, Args &&...args) {
  cout << t << " ";
  print(forward<Args>(args)...);
}
void solve(long long tc) {
  vector<long long> a(7);
  cin >> a;
  if (a[0] + a[1] == a[2]) a[2] = a[3];
  cout << a[0] << " " << a[1] << " " << a[2] << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(12) << fixed;
  long long tests = 1;
  cin >> tests;
  for (long long tt = 1; tt <= tests; tt++) solve(tt);
  return 0;
}
