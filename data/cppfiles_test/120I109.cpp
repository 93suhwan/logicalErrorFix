#include <bits/stdc++.h>
const long long MOD = 1e9 + 7;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
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
  int first = 0;
  cerr << '{';
  for (auto &i : x) cerr << (first++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
void test_case() {
  int a, b;
  cin >> a >> b;
  int cnt = 0;
  long long ans;
  for (long long i = 1; i <= b; i *= 2) {
    ans = i;
    if (ans >= a) break;
  }
  for (int i = a; i <= b; i++) {
    if ((i & ans) == 0)
      cnt++;
    else
      ans &= i;
  }
  int mn = (b - a + 1) / 2;
  if (a % 2 == 0 && b % 2 == 0) mn++;
  cout << min(mn, cnt) << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int te = 1;
  cin >> te;
  while (te--) {
    test_case();
  }
}
