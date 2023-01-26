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
void solve() {
  long long n;
  cin >> n;
  map<long long, long long> m1, m2;
  map<pair<long long, long long>, long long> m3;
  vector<long long> a(n), b(n);
  map<long long, vector<long long>> mt;
  for (long long i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    m1[a[i]]++;
    m2[b[i]]++;
    m3[{a[i], b[i]}]++;
    mt[a[i]].push_back(b[i]);
  }
  long long ans = 0;
  for (auto i : mt) {
    vector<long long> temp = i.second;
    map<long long, long long> mt1;
    for (long long j : temp) {
      mt1[j]++;
      m2[j]--;
    }
    for (auto j : mt1) {
      ans += (((j.second) * (j.second - 1) / 2) *
              (n - ((long long)(temp).size()) - m2[j.first]));
      ans +=
          (j.second * (((long long)(temp).size()) - j.second) * (m2[j.first]));
      ans += (((j.second) * (j.second - 1) / 2) * (m2[j.first]));
      ans += ((j.second) * (j.second - 1) / 2 *
              (((long long)(temp).size()) - j.second));
      ans += ((j.second) * (j.second - 1) * (j.second - 2) / 6);
    }
    for (long long j : temp) {
      mt1[j]++;
      m2[j]++;
    }
  }
  cout << (n * (n - 1) * (n - 2) / 6 - ans) << "\n";
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
