#include <bits/stdc++.h>
using namespace std;
void _print(bool t) { cerr << t; }
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
template <class T>
void _print(vector<T> v) {
  cerr << "[  ";
  for (T i : v) {
    _print(i);
    cerr << "  ";
  }
  cerr << "]\n";
}
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ", ";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(set<T> v) {
  cerr << "[  ";
  for (T i : v) {
    _print(i);
    cerr << "  ";
  }
  cerr << "]\n";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[  ";
  for (T i : v) {
    _print(i);
    cerr << "  ";
  }
  cerr << "]\n";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[  ";
  for (auto i : v) {
    _print(i);
    cerr << "  ";
  }
  cerr << "]\n";
}
template <class T>
void _print(T v[], long long n) {
  cerr << "[  ";
  for (long long i = 0; i < n; i++) {
    _print(v[i]);
    cerr << "  ";
  }
  cerr << "]\n";
}
struct BIT {
  vector<long long> values;
  long long N, LOGN;
  void init(long long n) {
    N = n;
    LOGN = ceil(log2(N));
    values.assign(N + 1, 0);
  }
  void update(long long idx, long long val) {
    while (idx <= N) {
      values[idx] += val;
      idx += idx & -idx;
    }
  }
  long long sum(long long idx) {
    long long sum = 0;
    while (idx > 0) {
      sum += values[idx];
      idx -= idx & -idx;
    }
    return sum;
  }
  long long rangeSum(long long i, long long j) {
    return sum(j) - (i == 1 ? 0 : sum(i - 1));
  }
};
void run() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << "YES\n";
    return;
  }
  if (n == 2) {
    if (a[1] >= a[0])
      cout << "YES\n";
    else
      cout << "NO\n";
    return;
  }
  set<long long> s;
  for (long long i = 0; i < n; i++) s.insert(a[i]);
  if (s.size() != n) {
    cout << "YES\n";
    return;
  }
  BIT ds;
  ds.init(n + 10);
  long long ans = 0;
  for (long long i = n - 1; i >= 0; i--) {
    ans += ds.sum(a[i] - 1);
    ds.update(a[i], 1);
  }
  if (ans % 2 == 0)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie();
  long long t;
  cin >> t;
  for (long long tc = 1; tc <= t; tc++) {
    run();
  }
}
