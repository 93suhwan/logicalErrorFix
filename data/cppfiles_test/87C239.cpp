#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
const long long mod = 1e9 + 7;
const long long N = 1e5 + 5;
const long long Sz = 1e6 + 5;
string to_string(const string& s) { return '"' + s + '"'; }
void DBG() { cerr << "]" << endl; }
template <class H, class... T>
void DBG(H h, T... t) {
  cerr << to_string(h);
  if (sizeof...(t)) cerr << ", ";
  DBG(t...);
}
void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen(""
            ".inp",
            "r")) {
    freopen(
        ""
        ".inp",
        "r", stdin);
    freopen(
        ""
        ".out",
        "w", stdout);
  }
}
long long n, a[200];
void test_case() {
  cin >> n;
  long long result = 0, pre = 0;
  for (long long i = (1); i <= (n); ++i) {
    cin >> a[i];
    if (a[i] <= i + result) {
      ++pre;
      continue;
    }
    result += a[i] - pre - 1;
    pre = a[i];
  }
  cout << result << '\n';
}
signed main() {
  setIO();
  long long TC = 1;
  cin >> TC;
  while (TC--) {
    test_case();
  }
  return 0;
}
