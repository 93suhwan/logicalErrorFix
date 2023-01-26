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
  int n;
  string str[2];
  cin >> n >> str[0] >> str[1];
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    if (str[0][i] == '0') cnt++;
    if (str[1][i] == '0') cnt++;
    if (cnt == 2) {
      if (i + 1 < n && str[0][i + 1] == '1' && str[1][i + 1] == '1') {
        i++;
        ans += 2;
      } else
        ans++;
    } else if (cnt == 0) {
      if (i + 1 < n && str[0][i + 1] == '0' && str[1][i + 1] == '0') {
        i++;
        ans += 2;
      }
    } else
      ans += 2;
  }
  cout << ans << "\n";
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
