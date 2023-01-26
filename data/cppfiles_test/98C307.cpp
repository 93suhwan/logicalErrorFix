#include <bits/stdc++.h>
using namespace std;
void _print(long long int t) { cerr << t; }
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
template <class T>
void print(const T *const arr, long long int count) {
  for (long long int i = 0; i < count; ++i) {
    _print(arr[i]);
    cerr << " ";
  }
  cerr << '\n';
}
void Solve() {
  string s;
  cin >> s;
  string t;
  cin >> t;
  long long int m = t.size();
  if (m == 1) {
    cout << 0;
    return;
  }
  map<char, long long int> mp;
  for (long long int i = 0; i < 26; i++) {
    mp[s[i]] = i;
  }
  long long int ans = 0;
  for (long long int i = 1; i < m; i++) {
    char c1 = t[i - 1];
    char c2 = t[i];
    ans += (abs(mp[c1] - mp[c2]));
  }
  cout << ans;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int T = 1;
  cin >> T;
  for (long long int i = 1; i < T + 1; i++) {
    Solve();
    cout << '\n';
  }
  return 0;
}
