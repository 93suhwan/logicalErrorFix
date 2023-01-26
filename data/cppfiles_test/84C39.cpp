#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (int i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i != v.size() - 1) os << ", ";
  }
  os << "]\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const deque<T>& v) {
  os << "[";
  for (int i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i != v.size() - 1) os << ", ";
  }
  os << "]\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "[";
  for (auto it : v) {
    os << it;
    if (it != *v.rbegin()) os << ", ";
  }
  os << "]\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v) {
  for (auto it : v) os << it.first << " : " << it.second << "\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  os << "(";
  os << v.first << ", " << v.second << ")";
  return os;
}
void go() { cin.tie(nullptr)->sync_with_stdio(false); }
void solve_case() {
  long long n, s, d;
  cin >> n >> s;
  if (n % 2 == 0) {
    d = n / 2 + 1;
  } else {
    d = (n + 1) / 2;
  }
  long long ans = s / d;
  cout << ans << '\n';
}
signed main() {
  go();
  long long t;
  cin >> t;
  while (t--) {
    solve_case();
  }
}
