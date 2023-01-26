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
void solve() {
  string str;
  cin >> str;
  unordered_map<char, int> make_pair;
  int count = 0;
  for (int i = 0; i < str.length(); i++) {
    if (make_pair[str[i]] > 0) {
      make_pair[str[i]]++;
    } else {
      make_pair[str[i]]++;
      count++;
    }
  }
  if (count == 1 && str.length() > 3) {
    cout << 1 << "\n";
    return;
  }
  if (str.length() == 1) {
    cout << 0 << "\n";
    return;
  }
  cout << str.length() / 2 << "\n";
}
int main() {
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
