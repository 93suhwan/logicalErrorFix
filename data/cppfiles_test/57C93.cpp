#include <bits/stdc++.h>
using namespace std;
void dbg_out() { cerr << "\b\b )" << '\n'; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << H << ", ";
  dbg_out(T...);
}
template <class T>
using vc = vector<T>;
struct pair_hash {
  template <class T1, class T2>
  size_t operator()(pair<T1, T2> const& pair) const {
    size_t h1 = hash<T1>()(pair.first);
    size_t h2 = hash<T2>()(pair.second);
    return h1 ^ h2;
  }
};
namespace MYpair {
template <typename T1, typename T2>
pair<T1, T2>& operator+=(pair<T1, T2>& p1, const pair<T1, T2>& p2) {
  p1.first += p2.first, p1.second += p2.second;
  return p1;
}
template <typename T1, typename T2>
pair<T1, T2>& operator-=(pair<T1, T2>& p1, const pair<T1, T2>& p2) {
  p1.first -= p2.first, p1.second -= p2.second;
  return p1;
}
template <typename T1, typename T2>
pair<T1, T2> operator+(pair<T1, T2> p1, const pair<T1, T2>& p2) {
  return p1 += p2;
}
template <typename T1, typename T2>
pair<T1, T2> operator-(pair<T1, T2> p1, const pair<T1, T2>& p2) {
  return p1 -= p2;
}
template <typename T>
T operator*(const pair<T, T>& p1, const pair<T, T>& p2) {
  return p1.first * p2.first + p1.second * p2.second;
}
template <typename T>
T operator^(const pair<T, T>& p1, const pair<T, T>& p2) {
  return p1.first * p2.second - p2.first * p1.second;
}
template <typename T>
pair<T, T>& operator*=(pair<T, T>& p1, const T& p2) {
  p1.first *= p2;
  p1.second *= p2;
  return p1;
}
template <typename T>
pair<T, T> operator*(pair<T, T> p1, const T& p2) {
  return p1 *= p2;
}
template <typename T>
pair<T, T> operator*(const T& p2, pair<T, T> p1) {
  return p1 *= p2;
}
}  // namespace MYpair
using namespace MYpair;
namespace MYio {
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  return os << p.first << ' ' << p.second;
}
template <typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, const vc<T>& a) {
  for (auto v : a) os << v << ' ';
  return os;
}
template <typename T>
istream& operator>>(istream& is, vc<T>& a) {
  for (auto& v : a) is >> v;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, const vc<vc<T>>& a) {
  for (auto& v : a) os << v << '\n';
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& a) {
  os << "debug(set):\n";
  for (auto& v : a) os << v << ' ';
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T, greater<T>>& a) {
  for (auto& v : a) os << v << ' ';
  return os;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const map<T1, T2>& a) {
  os << "debug(map):\n";
  for (auto& v : a)
    os << '\n' << setw(15) << v.frist << " : " << v.second << ' ';
  return os;
}
}  // namespace MYio
using namespace MYio;
const int P = 13331;
const int N = 1e3 + 10, M = 2 * N, MOD = 1e9 + 7, INF = 0x3f3f3f3f;
void solve(int caseT) {
  long long s, n, k, ans = 0;
  cin >> s >> n >> k;
  if (s == k) {
    cout << "YES" << '\n';
    return;
  }
  ans = s / (2 * k) * k;
  s %= (2 * k);
  ans += min(s + 1, k);
  cout << (ans > n ? "NO" : "YES") << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  T = 1;
  cin >> T;
  for (int i = 1; i <= T; i++) solve(i);
  return 0;
}
