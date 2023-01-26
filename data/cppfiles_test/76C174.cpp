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
  long long n, m;
  cin >> n >> m;
  vector<long long> dp(n + 1, 0);
  vector<long long> tdp(n + 1, 0);
  long long sum = 0;
  for (long long i = 1; i <= n; i++) {
    long long j = 2;
    tdp[i] += tdp[i - 1];
    if (i == 1)
      dp[i] = 1ll;
    else {
      dp[i] = (sum + tdp[i]) % m;
    }
    sum += dp[i];
    while (j * i <= n) {
      long long cn = j * i;
      long long nn = j * (i + 1);
      if (nn <= n) tdp[nn] = (m + (tdp[nn] - dp[i]) % m) % m;
      tdp[cn] = (dp[i] + tdp[cn]) % m;
      j++;
    }
  };
  cout << dp[n];
}
signed main() {
  init_code();
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
