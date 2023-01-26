#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
const long long U = 998244353;
string to_string(char c) { return "'" + string(1, c) + "'"; }
string to_string(string s) { return '"' + s + '"'; }
string to_string(bool f) {
  if (f)
    return "True";
  else
    return "False";
}
string to_string(const char *s) { return to_string((string)s); }
template <typename A>
string to_string(A);
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ": " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool f = false;
  string r = "{";
  for (auto x : v) {
    if (f) r += ", ";
    r += to_string(x);
    f = true;
  }
  return r += "}";
}
template <typename A>
string to_string(vector<vector<A>> v) {
  string r;
  for (auto x : v) r += "\n" + to_string(x);
  return r;
}
long long Nerr;
template <typename A>
string to_string(A *p) {
  return to_string(vector<A>(p, p + Nerr));
}
void err(istream_iterator<string>) { cerr << '\n'; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << to_string(a) << "; ";
  err(++it, args...);
}
template <typename T>
void kek(T ans) {
  cout << ans << '\n';
  exit(0);
}
signed main() {
  ios_base::sync_with_stdio(0);
  long long TESTS = 1;
  cin >> TESTS;
  while (TESTS--) {
    long long n;
    cin >> n;
    long long freq[31] = {};
    for (long long i = 0; i < n; i++) {
      long long t;
      cin >> t;
      for (long long j = 0; j < 30; j++) {
        if (t & (1 << j)) freq[j]++;
      }
    }
    for (long long i = 1; i < n + 1; i++) {
      bool f = true;
      for (long long j = 0; j < 30; j++) {
        if (freq[j] % i) f = false;
      }
      if (f) cout << i << " ";
    }
    cout << '\n';
  }
}
