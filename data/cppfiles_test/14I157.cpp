#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int min(long long int a, long long int b) {
  if (a < b) return a;
  return b;
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
long long int _count(vector<long long int> &d) {
  long long int cnt = 0;
  for (auto x : d)
    if (x == 0) cnt++;
  return cnt;
}
void solve() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> a(n), d(n);
  {
    for (auto &x : a) cin >> x;
  };
  for (long long int i = 0; i < n; ++i) d[i] = a[i] - (i + 1);
  long long int res = 0;
  long long int good = 0, bad = 0;
  long long int _k = _count(d);
  if (_k >= k) {
    cout << "0\n";
    return;
  }
  for (long long int i = 0; i < n; ++i) {
    ;
    if (d[i] > 0) {
      d[i] = 2 * n + 1;
      for (long long int j = i; j < n; j++) d[j]++;
      res++;
    } else if (d[i] < 0) {
      good = 0, bad = 0;
      for (long long int j = 0; j < i; ++j)
        if (d[j] == 0)
          good++;
        else if (d[j] <= n)
          bad++;
      long long int c = -1 * d[i];
      if (bad >= c) {
        for (long long int j = i; j < n; j++) d[j] += c;
        ;
        res += c;
        for (long long int j = 0; j < i; ++j)
          if (d[j] != 0) {
            d[j] = 2 * n + 1;
            c--;
            if (c == 0) break;
          }
      }
    }
    _k = _count(d);
    if (_k >= k) break;
  }
  _k = _count(d);
  ;
  if (_k >= k)
    cout << res << "\n";
  else
    cout << "-1\n";
}
int main() {
  std::ios_base::sync_with_stdio(false);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
