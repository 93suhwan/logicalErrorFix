#include <bits/stdc++.h>
using namespace std;
template <typename F, typename S>
ostream &operator<<(ostream &os, const pair<F, S> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename F, typename S>
ostream &operator<<(ostream &os, const map<F, S> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << it->first << " = " << it->second;
  }
  return os << "]";
}
void faltu() { cerr << endl; }
template <typename T>
void faltu(T a[], int n) {
  for (int i = 0; i < n; ++i) cerr << a[i] << ' ';
  cerr << endl;
}
template <typename T, typename... hello>
void faltu(T arg, const hello &...rest) {
  cerr << arg << ' ';
  faltu(rest...);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s, st;
    int n;
    cin >> n;
    cin >> s >> st;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != st[i])
        ans += 2;
      else if (s[i] == '1') {
        while (i < n) {
          if (s[i] == '0' || st[i] == '0') {
            ans += 2;
            break;
          }
          i++;
        }
      } else if (s[i] == '0') {
        i++;
        if (s[i] == '0' && st[i] == '0') {
          ans += 2;
        } else if (s[i] == '1' && st[i] == '0') {
          ans += 3;
        } else if (s[i] == '0' && st[i] == '1')
          ans += 3;
        else if (s[i] == '1' && st[i] == '1')
          ans += 2;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
