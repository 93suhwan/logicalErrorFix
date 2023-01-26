#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(unsigned t) { cerr << t; }
void _print(unsigned long t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
void _print(float t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(const char* t) { cerr << t; }
void _print(const string& t) { cerr << t; }
void _print(bool t) { cerr << (t ? "true" : "false"); }
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
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long INF = (long long)1e18 + 100;
const long long MOD = (long long)1e9 + 7;
const long long N = (long long)1e5 + 7;
void init() {}
void solve(long long test_case) {
  long long n;
  cin >> n;
  n++;
  long long cnt = 0;
  cnt = n / 10;
  cout << cnt << endl;
}
int32_t main() {
  long long tt = (long long)clock();
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  init();
  long long t = 1;
  if (1) cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve(i);
  }
  return 0;
}
