#include <bits/stdc++.h>
using namespace std;
const long long int MAX = 2e5 + 2;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
T rand(T a, T b) {
  return uniform_int_distribution<T>(a, b)(rng);
}
template <class T>
T rand() {
  return uniform_int_distribution<T>()(rng);
}
void _print(long long int t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
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
  long long int n;
  cin >> n;
  string s;
  s.clear();
  cin >> s;
  long long int c = 0;
  for (long long int i = 0; i < n - 1; i++) {
    c += (s[i] != '0' ? s[i] - '0' + 1 : 0);
  }
  c += s[n - 1] - '0';
  cout << c << endl;
}
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  }
  long long int t = 1;
  cin >> t;
  for (long long int i = 0; i < t; i++) {
    solve();
  }
}
