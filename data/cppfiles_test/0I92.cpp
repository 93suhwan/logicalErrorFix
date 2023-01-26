#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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
long long int mod = 1000000007;
bool cmp(pair<string, long long int> &a, pair<string, long long int> &b) {
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < a.first.size(); i++) {
    if (i % 2 == 0) {
      if (a.first[i] == b.first[i]) {
        continue;
      } else if (a.first[i] > b.first[i]) {
        cnt1++;
      } else {
        cnt2++;
      }
    } else {
      if (a.first[i] == b.first[i]) {
        continue;
      } else if (a.first[i] > b.first[i]) {
        cnt2++;
      } else {
        cnt1++;
      }
    }
  }
  return cnt2 > cnt1;
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  string s;
  vector<pair<string, long long int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i + 1;
  }
  sort(v.begin(), v.end(), cmp);
  ;
  for (auto it : v) {
    cout << it.second << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
