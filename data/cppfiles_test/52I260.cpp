#include <bits/stdc++.h>
using namespace std;
template <class T>
void _print(T a) {
  cerr << a;
}
template <class T>
void _print(vector<T> v) {
  cerr << "[";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(set<T> s) {
  cerr << "[";
  for (T i : s) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> s) {
  cerr << "[";
  for (T i : s) {
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
template <class T, class V>
void _print(unordered_map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
void solve() {
  float n;
  cin >> n;
  vector<float> a(n);
  float sum = 0;
  for (float i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a.begin(), a.end());
  double curr = 0;
  double ans = INT_MIN;
  for (float i = 0; i < n - 1; i++) {
    curr += a[i];
    double aa = (curr) / (i + 1);
    double bb = (sum - curr) / (n - i - 1);
    double cc = aa + bb;
    ans = max(ans, cc);
  }
  cout << fixed << setprecision(14) << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solve();
  }
}
