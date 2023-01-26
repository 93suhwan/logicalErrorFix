#include <bits/stdc++.h>
using namespace std;
void fio() {}
template <typename T>
void TIME(T start, T end) {}
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return a.second < b.second;
}
bool compBySec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return a.second == b.second ? a.first < b.first : a.second < b.second;
}
const long long N = 3e5 + 5;
void solve() {
  long long k;
  cin >> k;
  long long num = 0;
  while (k) {
    num++;
    if (num % 10 != 3 && num % 3 != 0) k--;
  }
  cout << num << "\n";
}
int32_t main() {
  auto start = chrono::high_resolution_clock::now();
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  fio();
  long long t = 1;
  cin >> t;
  while (t--) solve();
  auto end = chrono::high_resolution_clock::now();
  TIME(start, end);
  return 0;
}
