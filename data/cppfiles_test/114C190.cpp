#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const int MOD = 1000000007;
const double eps = 0.0000000001;
int tt, n;
int A[200005];
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  sort(A, A + n);
  for (int i = 1; i < n / 2 + 1; i++) cout << A[i] << " " << A[0] << "\n";
}
int main() {
  cin >> tt;
  while (tt--) solve();
}
