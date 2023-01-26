#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void show(T&&... args) {
  ((cerr << args << " "), ...);
}
template <typename F, typename S>
ostream& operator<<(ostream& os, const pair<F, S>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "{";
  typename vector<T>::const_iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "[";
  typename set<T>::const_iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& v) {
  os << "[";
  typename multiset<T>::const_iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename F, typename S>
ostream& operator<<(ostream& os, const map<F, S>& v) {
  os << "[";
  typename map<F, S>::const_iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << it->first << " = " << it->second;
  }
  return os << "]";
}
template <typename F, typename S>
ostream& operator<<(ostream& os, const unordered_map<F, S>& v) {
  os << "[";
  typename unordered_map<F, S>::const_iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << it->first << " = " << it->second;
  }
  return os << "]";
}
template <typename... T>
void read(T&... args) {
  ((cin >> args), ...);
}
template <typename... T>
void write(T&&... args) {
  ((cout << args << " "), ...);
}
int solve() {
  int n, q;
  string str;
  cin >> n >> q >> str;
  str = "#" + str;
  int mul = 1;
  vector<int> pre(n + 5);
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + mul * (str[i] == '+' ? 1 : -1);
    mul *= (-1);
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    if ((pre[r] - pre[l - 1]) == 0)
      cout << 0 << "\n";
    else if ((r - l + 1) & 1)
      cout << 1 << "\n";
    else
      cout << 2 << "\n";
  }
  return 0;
}
int main() {
  ;
  ;
  int t = 1, cs = 0;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
