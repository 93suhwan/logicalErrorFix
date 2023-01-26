#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
static inline void umin(T1 &x, T2 y) {
  if (y < x) x = y;
}
template <class T1, class T2>
static inline void umax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <class T>
void print(T t) {
  cerr << t;
}
template <class T1, class T2>
void print(pair<T1, T2> p) {
  cerr << "{ ";
  print(p.first);
  cerr << ", ";
  print(p.second);
  cerr << " }";
};
template <class T>
void print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
};
template <class T>
void print(set<T> s) {
  cerr << "[ ";
  for (T i : s) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
};
template <class T>
void print(multiset<T> ms) {
  cerr << "[ ";
  for (T i : ms) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
};
template <class T1, class T2>
void print(map<T1, T2> m) {
  cerr << "[ ";
  for (auto i : m) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
}
void flip(string &s, long long n, long long j) {
  for (long long i = 0; i < n; i++) {
    if (i != j) {
      if (s[i] == '0')
        s[i] = '1';
      else
        s[i] = '0';
    }
  }
}
void Solve() {
  long long n = 0;
  cin >> n;
  string a, b;
  cin >> a >> b;
  long long m = 0;
  for (long long i = 0; i < n; i++) m += (a[i] == b[i]);
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    if (a == b) break;
    if (a[i] == '1' and b[i] == '1') flip(a, n, i), ans++;
    if (a == b) break;
  }
  long long nm0 = 0, nm1 = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] == '0' and b[i] == '1') nm0++;
    if (a[i] == '1' and b[i] == '0') nm1++;
  }
  if (nm0 != nm1)
    ans = -1;
  else
    ans = min(m, n - m);
  cout << ans << '\n';
}
signed main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long TestCases = 1;
  cin >> TestCases;
  for (long long test = 1; test <= TestCases; test++) {
    Solve();
  }
  return 0;
}
