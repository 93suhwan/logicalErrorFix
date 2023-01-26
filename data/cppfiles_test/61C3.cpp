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
  long long n;
  string s;
  cin >> n >> s;
  for (long long i = 0, j = 0; i < n; i = j) {
    while (j < n && s[j] != '?') ++j;
    long long start = j;
    while (j < n && s[j] == '?') ++j;
    char c = 'R';
    if (start && s[start - 1] == 'R') c = 'B';
    if (j < n && ((s[j] == 'R' && (j - start) & 1) ||
                  (s[j] == 'B' && (j - start) % 2 == 0)))
      c = 'B';
    for (long long(k) = (start); (k) <= (j - 1); ++(k))
      s[k] = c, c = (c == 'R' ? 'B' : 'R');
  }
  cout << s;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int t1 = 1; t1 <= t; ++t1) {
    solve();
    cout << '\n';
  }
}
