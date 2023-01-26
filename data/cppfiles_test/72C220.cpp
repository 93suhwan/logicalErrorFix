#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << x; }
void __print(const char *x) { cerr << x; }
void __print(const string &x) { cerr << x; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) {
    cerr << (f++ ? ", " : "");
    __print(i);
  }
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) {
    cerr << ", ";
  }
  _print(v...);
}
string go(long long i, long long n, long long dist, string nw, long long k,
          string ori) {
  ;
  if (dist > k) {
    return "";
  }
  if (nw.substr(0, i) < ori.substr(0, i)) {
    return "";
  }
  if (i >= n) {
    return nw;
  }
  for (char val = '0'; val <= '9'; ++val) {
    nw[i] = val;
    bool found = false;
    for (long long j = 0; j < i; ++j) {
      if (nw[j] == val) {
        found = true;
        break;
      }
    }
    string chk = go(i + 1, n, dist + (found == false), nw, k, ori);
    if ((long long)chk.size()) {
      return chk;
    }
  }
  return "";
}
void solve() {
  long long n, k;
  cin >> n >> k;
  string s = to_string(n);
  long long dist = 0;
  map<char, long long> g;
  for (auto ch : s) {
    g[ch]++;
  }
  string ans =
      go(0, (long long)s.size(), 0, string((long long)s.size(), '0'), k, s);
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
