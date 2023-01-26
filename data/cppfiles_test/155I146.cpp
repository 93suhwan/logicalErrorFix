#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
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
void solve() {
  long long n;
  cin >> n;
  vector<long long> p(n), q(n);
  string s;
  for (long long i = 0; i < (n); i++) {
    cin >> p[i];
  }
  cin >> s;
  long long tot = 0;
  for (long long i = 0; i < (n); i++) {
    if (s[i] == '0') tot++;
  }
  tot++;
  if (tot == 1 || tot == n + 1) {
    for (long long i = 0; i < (n); i++) {
      cout << p[i] << " ";
    }
    cout << "\n";
    return;
  }
  long long curr = 1;
  for (long long i = 0; i < (n); i++) {
    if (s[i] == '0') {
      q[i] = curr;
      curr++;
    } else {
      q[i] = tot;
      tot++;
    }
  }
  for (long long i = 0; i < (n); i++) {
    cout << q[i] << " ";
  }
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
