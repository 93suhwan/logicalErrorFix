#include <bits/stdc++.h>
using namespace std;
namespace Debug {
void __print(signed x) { cout << x; }
void __print(long x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned x) { cout << x; }
void __print(unsigned long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(float x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << '\'' << x << '\''; }
void __print(const char *x) { cout << '\"' << x << '\"'; }
void __print(const string &x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cout << '{';
  __print(x.first);
  cout << ',';
  __print(x.second);
  cout << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cout << '{';
  for (auto &i : x) cout << (f++ ? "," : ""), __print(i);
  cout << "}";
}
void _print() { cout << "]" << endl; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cout << ", ";
  _print(v...);
}
}  // namespace Debug
using namespace Debug;
template <typename Arg1>
void p(Arg1 &&arg1) {
  cout << arg1;
}
template <typename Arg1, typename... Args>
void p(Arg1 &&arg1, Args &&...args) {
  cout << arg1;
  p(args...);
}
template <typename Arg1>
void read(Arg1 &&arg1) {
  cin >> arg1;
}
template <typename Arg1, typename... Args>
void read(Arg1 &&arg1, Args &&...args) {
  cin >> arg1;
  read(args...);
}
const bool DEBUG = true;
long long power(long long n, long long m) {
  long long p = 1;
  if (m == 0) return 1;
  p = (power(n, m / 2) % 1000000007);
  p = (p % 1000000007 * p % 1000000007) % 1000000007;
  return (m & 1 ? ((p % 1000000007 * n % 1000000007) % 1000000007)
                : (p % 1000000007));
}
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long> > v[5];
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    vector<long long> cnt(5, 0);
    for (auto x : s) cnt[x - 'a']++;
    for (long long i = 0; i < 5; i++) {
      v[i].push_back({cnt[i] - ((long long)s.size() - cnt[i]),
                      ((long long)s.size() - cnt[i])});
    }
  }
  for (long long i = 0; i < 5; i++) sort(v[i].rbegin(), v[i].rend());
  for (long long i = 0; i < 5; i++) {
    for (long long j = 0; j < (long long)v[i].size(); j++) {
      v[i][j].first = v[i][j].first + v[i][j].second;
    }
  }
  long long ans = 0;
  for (long long i = 0; i < 5; i++) {
    long long count1 = 0, count = 0;
    long long cnt1 = 0;
    for (long long j = 0; j < n; j++) {
      long long f1 = v[i][j].first;
      long long s1 = v[i][j].second;
      count1 += f1;
      count += s1;
      if (count1 > count) {
        ++cnt1;
      }
    }
    ans = max(ans, cnt1);
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  cerr << (float)clock() / CLOCKS_PER_SEC * 1000 << " ms"
       << "\n";
  return 0;
}
