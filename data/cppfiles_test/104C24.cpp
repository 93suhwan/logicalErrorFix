#include <bits/stdc++.h>
using namespace std;
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
long long x = 0;
inline long long first(long long t) { return abs(x - 2 * t); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, long long> > v(n), ranges(n), ranget(n);
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    long long lb = 0, ub = 0;
    x = n * m;
    for (int i = 0; i < n; i++) {
      lb += max(0LL, m - v[i].second);
      ub += min(m, v[i].first);
      ranget[i] = {max(0LL, m - v[i].second), min(m, v[i].first)};
      ranges[i] = {lb, ub};
      x += v[i].first - v[i].second;
      ;
      ;
    };
    ;
    long long l = lb;
    long long r = ub;
    while (r - l > 4LL) {
      long long m1 = (r + l) / 2;
      long long m2 = (r + l) / 2 + 1;
      if (first(m1) > first(m2))
        l = m1;
      else
        r = m2;
    }
    long long ans = LLONG_MAX;
    long long theta;
    for (long long i = l; i <= r; i++) {
      if (ans > first(i)) {
        ans = first(i);
        theta = i;
      }
    }
    cout << ans << "\n";
    ;
    vector<pair<long long, long long> > first(n);
    ;
    for (int i = n - 1; i >= 1; i--) {
      if (theta - ranget[i].second < ranges[i - 1].first) {
        long long eata = theta - ranges[i - 1].first;
        long long eatb = m - eata;
        theta = ranges[i - 1].first;
        first[i] = {eata, eatb};
      } else {
        long long eata = ranget[i].second;
        long long eatb = m - eata;
        theta -= ranget[i].second;
        first[i] = {eata, eatb};
      }
    }
    first[0] = {theta, m - theta};
    for (int i = 0; i < n; i++)
      cout << first[i].first << " " << first[i].second << "\n";
  }
}
