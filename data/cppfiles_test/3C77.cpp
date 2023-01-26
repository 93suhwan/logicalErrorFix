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
  long long int l = 1e8;
  string s;
  cin >> s;
  long long int n = ((long long int)(s).size());
  long long int cnt = 0;
  vector<long long int> v;
  for (long long int i = 0; i < n; i++) {
    if (s[i] == 'X') v.push_back(i);
  }
  for (long long int i = 0; i <= l; i += 25) {
    string s1 = to_string(i);
    string t = s;
    if (((long long int)(s1).size()) > ((long long int)(t).size())) break;
    if (((long long int)(s1).size()) < ((long long int)(t).size())) continue;
    if (s1 == t) {
      cnt++;
      continue;
    }
    for (long long int j = 0; j < n; j++) {
      if (t[j] == '_') {
        t[j] = s1[j];
      }
    }
    if (((long long int)(v).size()) > 0) {
      bool flag = true;
      for (long long int j = 1; j < ((long long int)(v).size()); j++) {
        if (s1[v[j]] != s1[v[j - 1]]) {
          flag = false;
          ;
        }
      }
      if (!flag) continue;
      for (long long int j = 0; j < ((long long int)(v).size()); j++) {
        t[v[j]] = s1[v[j]];
      }
    }
    if (t == s1) cnt++;
  }
  cout << cnt;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int T = 1;
  for (long long int i = 1; i < T + 1; i++) {
    Solve();
    cout << '\n';
  }
  return 0;
}
