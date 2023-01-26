#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if (a.first.first != b.first.first) return a.first.first > b.first.first;
  if (a.first.second != b.first.second) return a.first.second < b.first.second;
  return a.second < b.second;
}
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
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
bool compare(const pair<int, int>& i, const pair<int, int>& j) {
  return i.second < j.second;
}
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  bool all_neg = true;
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] > 0) {
      all_neg = false;
    }
  }
  int sum = 0, ans = 0;
  sort(v.begin(), v.end());
  ;
  ;
  sort(v.begin(), v.end());
  for (int i = 0; i < n - 1; i++) {
    sum += v[i];
  };
  ;
  cout << fixed << setprecision(10) << v[n - 1] + (double)sum / (n - 1) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
