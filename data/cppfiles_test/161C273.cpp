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
  long long n;
  cin >> n;
  map<pair<long long, long long>, long long> ans;
  map<long long, vector<long long>> last;
  vector<pair<long long, long long>> arr(n);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
    last[arr[i].second].push_back(arr[i].first);
  }
  for (auto ele : last) {
    sort((ele.second).begin(), (ele.second).end());
    long long p1 = 0;
    for (long long i = 0; i < (ele.second).size() - 1; i++) {
      ans[{ele.second[i], ele.first}] = ele.second[i + 1] - 1;
    }
    ans[{ele.second[(ele.second).size() - 1], ele.first}] = ele.first;
  }
  for (auto ele : ans) {
    cout << ele.first.first << " " << ele.first.second << " " << ele.second
         << endl;
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
