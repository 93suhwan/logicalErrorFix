#include <bits/stdc++.h>
using namespace std;
template <typename T, typename V>
ostream& operator<<(ostream& os, const pair<T, V>& p) {
  os << "{" << p.first << ", " << p.second << "}";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[ ";
  for (T e : v) os << e << " ";
  os << "]"
     << "\n";
  return os;
}
template <typename T, typename V>
ostream& operator<<(ostream& os, const map<T, V>& mp) {
  os << "[ "
     << "\n";
  for (auto x : mp) os << x << "\n";
  os << " ]"
     << "\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "[ ";
  for (T e : v) os << e << " ";
  os << "]"
     << "\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& v) {
  os << "[ ";
  for (T e : v) os << e << " ";
  os << "]"
     << "\n";
  return os;
}
template <typename T, typename V>
istream& operator>>(istream& is, pair<T, V>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (int i = 0; i < v.size(); i++) is >> v[i];
  return is;
}
void solve() {
  int n;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.insert(x);
  }
  int cnt = n / 2;
  vector<int> v(s.begin(), s.end());
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      if (s.find(v[j] % v[i]) == s.end()) {
        cout << v[j] << " " << v[i] << "\n";
        cnt--;
        if (cnt == 0) return;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
