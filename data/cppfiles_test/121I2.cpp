#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
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
mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
long long n;
string a, b;
void solve() {
  cin >> n >> a >> b;
  long long z = 0, o = 0, ez = 0, eo = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      if (a[i] == '0')
        z++;
      else
        o++;
    } else {
      if (a[i] == '0')
        ez++;
      else
        eo++;
    }
  }
  long long ans = INT_MAX;
  if (z == o) {
    ans = 2 * z;
  }
  if (ez == 1 and eo == 2) {
    ans = min(ans, 3ll);
  }
  if (eo == 1 and ez == 0) {
    ans = min(ans, 1ll);
  }
  if (ans == INT_MAX) ans = -1;
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
