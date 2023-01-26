#include <bits/stdc++.h>
using namespace std;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
istream& operator>>(istream& is, vector<T>& vec) {
  for (auto& v : vec) is >> v;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[ ";
  for (int i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i != v.size() - 1) os << ", ";
  }
  os << " ]\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "[ ";
  for (auto it : v) {
    os << it;
    if (it != *v.rbegin()) os << ", ";
  }
  os << " ]\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& v) {
  os << "[ ";
  for (auto it : v) os << it << ", ";
  os << " ]\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v) {
  os << "{ ";
  for (auto it : v) os << it.first << " : " << it.second << ", ";
  os << " }\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  os << "(";
  os << v.first << ", " << v.second << ")";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, priority_queue<T> p) {
  os << "[ ";
  while (!p.empty()) {
    os << p.top() << " ,";
    p.pop();
  }
  os << " ]\n";
  return os;
}
const long long INF = 1e18;
const long long mod = 1e9 + 7;
inline long long pmod(long long i, long long n = mod) {
  return (i % n + n) % n;
}
inline long long cdiv(long long a, long long b) { return (a + b - 1) / b; }
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<bool> a(n);
  for (long long(i) = (1); (i) <= (m); ++(i)) {
    long long u, v, w;
    cin >> u >> v >> w;
    a[v - 1] = 1;
  }
  long long u;
  for (long long(i) = (0); (i) <= (n - 1); ++(i))
    if (!a[i]) {
      u = i + 1;
      break;
    }
  for (long long(i) = (1); (i) <= (n); ++(i)) {
    if (i != u) cout << i << ' ' << u << '\n';
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int t1 = 1; t1 <= t; ++t1) {
    solve();
  }
}
