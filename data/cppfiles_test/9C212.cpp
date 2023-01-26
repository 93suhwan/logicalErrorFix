#include <bits/stdc++.h>
using namespace std;
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '"' << x << '"'; }
void __print(const string &x) { cerr << '"' << x << '"'; }
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
void _print() { cerr << "]\n "; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
void solve() {
  string s;
  cin >> s;
  unordered_map<char, long long> mp;
  unordered_map<long long, long long> mp1;
  long long red = 0;
  for (long long i = 0; i < s.length(); i++) {
    mp[s[i]]++;
  }
  for (auto p : mp) {
    mp1[p.second]++;
  }
  for (auto p : mp1) {
    if (p.first > 1 || p.second > 1) {
      if (p.first == 1)
        red += p.second / 2;
      else
        red += p.second;
    }
  }
  cout << red;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tt;
  cin >> tt;
  while (tt--) {
    solve();
    cout << "\n";
  }
  return 0;
}
