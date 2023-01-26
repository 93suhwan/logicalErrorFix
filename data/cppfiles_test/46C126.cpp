#include <bits/stdc++.h>
using namespace std;
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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1, i, j, k, n, m, x, y, ans, sum, sz, a, b, c, d, val, lo, hi,
            mid, tmp;
  char ch;
  string s, rs, str, s1, s2;
  bool ok;
  double dou1, dou2, dou3;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long long> v(n);
    ans = 0;
    for (i = 0; i < n; i++) {
      cin >> v[i];
    }
    x = v.back();
    for (i = n - 2; i >= 0; i--) {
      if (v[i] > x) {
        x = v[i];
        ans++;
      }
    }
    cout << ans << endl;
  }
}
