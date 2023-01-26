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
inline void file_io(string path1 = "", string path2 = "") {
  if (path2.size() == 0) path2 = path1;
  freopen(path1.c_str(), "r", stdin);
  freopen(path2.c_str(), "w", stdout);
}
int func(string str, int n) {
  int st = 1, cur = 1, near = 1;
  for (auto& val : str) {
    if (val == '0') {
      if (cur == 1) {
        if (n - near > 0)
          st++, near++;
        else
          return st;
      } else
        cur--;
    } else {
      if (cur + 1 <= n)
        cur++, near = max(near, cur);
      else
        return st;
    }
  }
  return st;
}
int solve() {
  int n, m;
  string str, row, col;
  cin >> n >> m >> str;
  row = col = "";
  for (auto& val : str) {
    if (val == 'L')
      col += "0";
    else if (val == 'R')
      col += "1";
    else if (val == 'U')
      row += "0";
    else if (val == 'D')
      row += "1";
  }
  int x = func(row, n);
  int y = func(col, m);
  cout << x << " " << y << "\n";
  return 0;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  ;
  ;
  int t = 1, cs = 0;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
