#include <bits/stdc++.h>
using namespace std;
void __print(long long x) { cerr << x; }
void __print(long x) { cerr << x; }
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
void solve();
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test;
  cin >> test;
  while (test--) {
    solve();
  }
}
bool check1(string &s, string &st, long long p, long long n) {
  if (s[p] == '0' && st[p] == '1') return true;
  if (s[p] == '1' && st[p] == '0') return true;
  return false;
}
bool check2(string &s, string &st, long long p, long long n) {
  if (p + 1 < n && s[p] == '1') {
    if (s[p + 1] == '0' && st[p + 1] == '0') return true;
  }
  if (p + 1 < n && s[p] == '0') {
    if (s[p + 1] == '1' && st[p + 1] == '1') return true;
  }
  return false;
}
bool check3(string &s, string &st, long long p, long long n) {
  if (s[p] == '0') {
    return true;
  }
  return false;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  multiset<long long> s;
  long long ans = 0;
  for (long long i = 0; i < m; i++) {
    long long x;
    cin >> x;
    s.insert(x);
    auto it = s.lower_bound(x);
    if (it == s.end()) {
      ans += i;
    } else {
      long long len = 0;
      for (auto it1 = s.begin(); it1 != s.end(); it1++) {
        if (it1 == it) {
          ans += len;
          break;
        }
        len++;
      }
    }
  }
  cout << ans << endl;
}
