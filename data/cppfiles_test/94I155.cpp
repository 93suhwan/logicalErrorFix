#include <bits/stdc++.h>
using namespace std;
void solve();
void _print(long long t) { cout << t; }
void _print(int t) { cout << t; }
void _print(string t) { cout << t; }
void _print(char t) { cout << t; }
void _print(long double t) { cout << t; }
void _print(double t) { cout << t; }
void _print(unsigned long long t) { cout << t; }
template <class T, class V>
void _print(pair<T, V> p) {
  cout << "{";
  _print(p.first);
  cout << ",";
  _print(p.second);
  cout << "}";
}
template <class T>
void _print(vector<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void _print(set<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void _print(multiset<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cout << "[ ";
  for (auto i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
void solve() {
  string s, s1, s2, s3;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (i % 2 == 0) {
      s1 += s[i];
    } else if (i % 2 == 1) {
      s2 += s[i];
    }
  }
  if (s2.empty()) {
    cout << stoi(s1) - 1;
    return;
  }
  cout << (stoi(s1) + 1) * (stoi(s2) + 1) - 2;
}
