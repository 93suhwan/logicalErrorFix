#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
bool comp1(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
bool comp2(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  int occAB = 0;
  int occBA = 0;
  for (int i = 1; i < n; i++) {
    if (s[i - 1] == 'a' && s[i] == 'b') occAB++;
    if (s[i - 1] == 'b' && s[i] == 'a') occBA++;
  }
  if (occAB == occBA) {
    cout << s << "\n";
    return;
  } else {
    if (occAB > occBA) {
      if (s[0] == 'a') {
        s[0] = 'b';
      } else if (s[n - 2] == 'a') {
        s[n - 2] = 'b';
      }
    } else {
      if (s[0] == 'b') {
        s[0] = 'a';
      } else if (s[n - 2] == 'b') {
        s[n - 2] = 'a';
      }
    }
    cout << s << "\n";
    return;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
