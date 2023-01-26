#include <bits/stdc++.h>
using namespace std;
void _print(long long int t) { cerr << t; }
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
void _print(unordered_map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
const long long int MOD = 1e9 + 7;
const long long int MX = 1e5 + 1;
long long int n;
long long int arr[MX];
long long int a, b, c, d, e, f, g, h;
void sourav() {
  int cnt1 = 0, cnt2 = 0;
  string s;
  cin >> s;
  if (s.size() & 1) {
    cout << "NO\n";
    ;
    return;
  }
  for (long long int i = 0; i < s.size(); i++) {
    if (s[i] == 'A') {
      cnt1++;
    } else if (s[i] == 'C') {
      cnt2++;
    }
  }
  if ((cnt1 + cnt2) == (s.size() - (cnt1 + cnt2))) {
    cout << "YES\n";
    ;
  } else {
    cout << "NO\n";
    ;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    sourav();
  }
  return 0;
}
