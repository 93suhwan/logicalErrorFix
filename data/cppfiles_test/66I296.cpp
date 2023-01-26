#include <bits/stdc++.h>
using namespace std;
void fio() {}
template <typename T>
void TIME(T start, T end) {}
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
  for (auto &i : x) cerr << (f++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return a.second < b.second;
}
bool compBySec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return a.second == b.second ? a.first < b.first : a.second < b.second;
}
const long long N = 1e5 + 5;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> v;
  long long temp = n;
  while (temp) {
    v.push_back(temp % 10);
    temp /= 10;
  }
  reverse(v.begin(), v.end());
  ;
  if (k == 1) {
    long long p = v[0];
    bool flag = 0;
    for (long long x : v) {
      if (x > p) {
        flag = 1;
      }
    }
    if (flag == 1) {
      for (long long i = 0; i < v.size(); ++i) cout << p + 1;
      cout << "\n";
    } else {
      for (long long i = 0; i < v.size(); ++i) cout << p;
      cout << "\n";
    }
  }
  if (k == 2) {
    long long i = 0;
    while (v[i] == v[0]) {
      i++;
    }
    if (i == v.size()) {
      cout << n << "\n";
      return;
    }
    long long p = v[i];
    for (long long k = i; k < v.size(); k++) {
      p = max(p, v[k]);
    }
    if (v[0] > p) {
      for (long long i = 0; i < v.size(); ++i) {
        if (v[i] <= p)
          cout << p;
        else
          cout << v[0];
      }
      cout << "\n";
    } else {
      for (long long i = 0; i < v.size(); ++i) {
        if (v[i] <= v[0])
          cout << v[0];
        else
          cout << p;
      }
      cout << "\n";
    }
  }
}
int32_t main() {
  auto start = chrono::high_resolution_clock::now();
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  fio();
  long long t = 1;
  cin >> t;
  while (t--) solve();
  auto end = chrono::high_resolution_clock::now();
  TIME(start, end);
  return 0;
}
