#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve();
void warm_up();
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  warm_up();
  solve();
  return 0;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  for (const T &e : v) out << e << " ";
  return out;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << p.first << " " << p.second;
  return out;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (T &e : v) {
    in >> e;
  }
  return in;
}
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}
void warm_up() {}
void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
