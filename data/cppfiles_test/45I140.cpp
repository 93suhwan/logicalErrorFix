#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
inline int ceili(int x, int y) { return (x + y - 1) / y; }
inline long long ceili(long long x, long long y) { return (x + y - 1) / y; }
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
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
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < (int)(n); ++i) cin >> a[i];
  vector<int> odd, even;
  for (int i = 0; i < (int)(n); ++i) {
    if (a[i] & 1)
      odd.push_back(i);
    else
      even.push_back(i);
  }
  if (n / 2 != min(((int)((odd).size())), ((int)((even).size())))) {
    cout << -1 << "\n";
    return;
  }
  int odd_pos = 0, even_pos = 0, cnt = 0;
  for (int i = 0; i < (int)(n - 1); ++i) {
    if ((a[i] & 1) && (!(a[i] & 1))) continue;
    if (a[i] & 1) {
      cnt += abs(i - even[even_pos]) - 1;
      int pos = even[even_pos];
      for (int j = 0; j < (int)(cnt); ++j) {
        ;
        if (pos < 1 || pos > n - 1) break;
        swap(a[pos], a[pos - 1]);
        ;
        --pos;
      }
      ++even_pos;
      ++i;
    } else {
      cnt += abs(i - odd[odd_pos]) - 1;
      int pos = odd[odd_pos];
      for (int j = 0; j < (int)(cnt); ++j) {
        if (pos < 1 || pos > n - 1) break;
        swap(a[pos], a[pos - 1]);
        --pos;
      }
      ++odd_pos;
      ++i;
    }
  }
  cout << cnt << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
