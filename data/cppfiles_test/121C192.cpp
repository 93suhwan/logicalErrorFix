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
void Solve() {
  long long n = 0;
  cin >> n;
  string a, b;
  cin >> a >> b;
  map<char, long long> am, bm;
  long long matching = 0;
  for (long long i = 0; i < n; i++) {
    matching += (a[i] == b[i]);
    am[a[i]]++;
    bm[b[i]]++;
  }
  long long ans = 9e18;
  if (am['1'] == bm['1']) ans = n - matching;
  if (bm['1'] == 1 + am['0']) ans = min(ans, matching);
  cout << (ans == 9e18 ? -1 : ans) << '\n';
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
