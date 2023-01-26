#include <bits/stdc++.h>
using namespace std;
void __print(long long x) { cerr << x; }
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
  long long f = 0;
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
template <long long D, typename T>
struct vec : public vector<vec<D - 1, T>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template <typename... Args>
  vec(long long n = 0, Args... args)
      : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}
};
template <typename T>
struct vec<1, T> : public vector<T> {
  vec(long long n = 0, const T &val = T()) : vector<T>(n, val) {}
};
const long long gf = 1e6 + 9;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long m, n;
    cin >> m >> n;
    long long a[m][n];
    long long mx[m];
    for (long long i = 0; i < m; i++)
      for (long long j = 0; j < n; j++) cin >> a[i][j];
    for (long long i = 0; i < m; i++) {
      long long lol = 0;
      for (long long j = 0; j < n; j++) {
        lol = max(lol, a[i][j]);
      }
      mx[i] = lol;
    }
    long long l = 1, r = (1e9 + 5);
    long long ans = 1;
    while (l <= r) {
      long long mid = (l + r) / 2;
      set<long long> s1[n];
      vector<long long> cnt(m);
      long long flag = 0;
      for (long long i = 0; i < n; i++) {
        long long lol = 0;
        for (long long j = 0; j < m; j++) {
          if (a[j][i] >= mid) cnt[j]++, lol++;
        }
        if (!lol) flag = 1;
      }
      sort(cnt.rbegin(), cnt.rend());
      long long var = 0;
      for (long long i = 0; i < min(n - 1, m); i++) {
        var += cnt[i];
      };
      if (var >= n && !flag) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
