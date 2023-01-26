#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& it : v) is >> it;
  return is;
}
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, set<T> second) {
  os << "{ ";
  for (auto s : second) os << s << " ";
  return os << "}";
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " |";
  __f(comma + 1, args...);
}
void display(vector<long long int> v) {
  for (long long int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << '\n';
}
void solve() {
  long long int n, s;
  cin >> n >> s;
  long long int div = n / 2;
  div++;
  cout << s / div << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
