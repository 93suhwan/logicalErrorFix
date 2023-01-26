#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
  for (auto& i : v) os << i << ' ';
  os << '\n';
  return os;
}
template <typename T, typename U>
istream& operator>>(istream& is, pair<T, U>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U> p) {
  os << p.first << ' ' << p.second;
  return os;
}
template <typename T, typename U>
void cmin(T& a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
void cmax(T& a, U b) {
  if (a < b) a = b;
}
const int N = 2e5 + 2, M = 1e9 + 7;
int tt = 1, n, k;
void solve() {
  cin >> n;
  vector<int> a(n);
  cin >> a;
  cout << (accumulate(a.begin(), a.end(), 0ll) % n != 0) << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> tt;
  while (tt--) solve();
}
