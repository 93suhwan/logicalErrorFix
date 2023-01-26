#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
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
void init_code() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
bool make(vector<long long> a, long long mid) {
  long long n = ((long long)(a).size());
  vector<long long> b = a;
  for (long long i = n - 1; i >= 2; i--) {
    if (a[i] < mid)
      return 0;
    else {
      long long extra = min(b[i], a[i] - mid);
      extra /= 3;
      a[i - 1] += extra;
      a[i - 2] += 2 * extra;
    }
  }
  if (a[0] >= mid && a[1] >= mid) return 1;
  return 0;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long f = 1, l = 1e9;
  long long ans = 1;
  while (f <= l) {
    long long mid = (f + l) / 2;
    if (make(a, mid)) {
      ans = max(ans, mid);
      f = mid + 1;
    } else {
      l = mid - 1;
    }
  }
  cout << ans << "\n";
}
signed main() {
  init_code();
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
