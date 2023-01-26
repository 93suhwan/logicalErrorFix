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
const long long int INF = 1e9 + 9;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void solve() {
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    long long n, a, b;
    cin >> n >> a >> b;
    vector<long long> ans;
    for (int i = 0; i < n; ++i) {
      ans.push_back(i + 1);
    }
    if ((a + b) > n - 2 || abs(a - b) > 1) {
      cout << -1 << "\n";
    } else {
      if (a == b) {
        for (long long i = 1, j = 1; j <= a; j++, i += 2)
          swap(ans[i], ans[i + 1]);
      }
      if (a > b) {
        for (long long i = n - 1, j = 1; j <= a; j++, i -= 2)
          swap(ans[i], ans[i - 1]);
      }
      if (a < b) {
        for (long long i = 0, j = 1; j <= b; j++, i += 2)
          swap(ans[i], ans[i + 1]);
      }
      for (long long i = 0; i < n; i++) {
        cout << ans[i] << " ";
      }
    }
    cout << "\n";
  }
}
int main() {
  fast();
  solve();
}
