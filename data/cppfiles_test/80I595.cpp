#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,fma,mmx,avx,tune=native")
using namespace std;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
bool ldequal(long double a, long double b) { return abs(a - b) < 1e-9; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const int N = 2e5 + 5;
bool tests = true;
void gen(){};
void solve() {
  int l1, r1, l2, r2, n;
  cin >> n;
  string s;
  cin >> s;
  int ind = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') ind = i;
  };
  int m = n / 2;
  ;
  if (ind == -1) {
    l1 = 0;
    r1 = m;
    l2 = 0;
    r2 = 2 * m;
    r1--;
    r2--;
  } else {
    if (ind < m) {
      r1 = n - 1;
      l1 = ind;
      r2 = n - 1;
      l2 = ind + 1;
    } else {
      l1 = 0;
      r1 = ind;
      l2 = 0;
      r2 = ind - 1;
    }
  }
  cout << l1 + 1 << " " << r1 + 1 << " " << l2 + 1 << " " << r2 + 1 << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  gen();
  long long test = 1;
  if (tests) cin >> test;
  for (int i = 1; i < test + 1; i++) {
    ;
    solve();
    cout << "\n";
  }
  return 0;
}
