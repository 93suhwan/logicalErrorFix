#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
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
const long long int MOD = 1e9 + 7;
const long long int INF = 1e6;
const long long int N = 2e5 + 2;
void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  long long int oo, zz, oz, zo;
  oo = zz = oz = zo = 0;
  auto cnt = [](string a, string b) -> int {
    int c10 = 0;
    int c01 = 0;
    int notEqual = 0;
    for (int i = 0; i < (a).size(); ++i) {
      if (a[i] != b[i]) {
        c10 += (a[i] == '1' && b[i] == '0');
        c01 += (a[i] == '0' && b[i] == '1');
        notEqual++;
      }
    }
    if (c10 == c01) return notEqual;
    return INF;
  };
  auto change = [&](string a, string b, char ch) -> int {
    int idx = -1;
    for (int i = 0; i < (a).size(); ++i) {
      if (a[i] == '1' && b[i] == ch) {
        idx = i;
        break;
      }
    }
    if (idx == -1) return INF;
    for (int i = 0; i < (a).size(); ++i) {
      if (idx == i) continue;
      a[i] = '0' + '1' - a[i];
    }
    return cnt(a, b);
  };
  int ans = cnt(a, b);
  ans = min(ans, 1 + change(a, b, '1'));
  ans = min(ans, 1 + change(a, b, '0'));
  if (ans >= INF) ans = -1;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) solve();
}
