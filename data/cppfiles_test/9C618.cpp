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
void solve() {
  string ans;
  cin >> ans;
  map<char, vector<int> > inds;
  for (int i = 0; i < ans.size(); i++) inds[ans[i]].push_back(i);
  int rem = 0;
  for (auto it = inds.begin(); it != inds.end(); it++) {
    while (it->second.size() > 2) it->second.pop_back();
    rem += it->second.size();
  }
  cout << rem / 2 << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ;
  int test = 1, i = 0;
  cin >> test;
  while (i++ != test) {
    solve();
  }
  return 0;
}
