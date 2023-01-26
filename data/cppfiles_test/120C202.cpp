#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
int N = 2e5 + 2;
vector<vector<int>> pre(N, vector<int>(21, 0));
void precalc() {
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < 21; ++j) {
      if ((i & (1 << j))) pre[i][j] = 1;
      pre[i][j] += pre[i - 1][j];
    }
  }
}
void solve() {
  int l, r;
  cin >> l >> r;
  int ans = 0;
  for (int i = 0; i < 21; ++i) {
    ans = max(ans, pre[r][i] - pre[l - 1][i]);
  }
  cout << r - l + 1 - ans << nl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  precalc();
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
