#include <bits/stdc++.h>
using namespace std;
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
  cerr << "]";
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
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[  ";
  for (T i : v) {
    _print(i);
    cerr << "  ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[  ";
  for (auto i : v) {
    _print(i);
    cerr << "  ";
  }
  cerr << "]";
}
template <class T>
void _print(T v[], long long n) {
  cerr << "[  ";
  for (long long i = 0; i < n; i++) {
    _print(v[i]);
    cerr << "  ";
  }
  cerr << "]";
}
string s;
long long dp[11][11][11];
long long solve(long long pos, long long first, long long second) {
  if (pos == 10) return 0;
  long long rem1 = 0, rem2 = 0;
  rem2 = (10 - pos + 1) / 2;
  rem1 = (10 - pos - rem2);
  if (first > second) {
    if (first - second > rem2) return 0;
  } else if (second > first) {
    if (second - first > rem1) return 0;
  }
  if (dp[pos][first][second] != -1) return dp[pos][first][second];
  long long &ans = dp[pos][first][second];
  ans = INT_MAX;
  if (s[pos] == '1') {
    ans = min(ans, 1 + solve(pos + 1, first + (pos & 1 ? 0 : 1),
                             second + (pos & 1 ? 1 : 0)));
  } else if (s[pos] == '0') {
    ans = min(ans, 1 + solve(pos + 1, first, second));
  } else {
    ans = min(ans, 1 + solve(pos + 1, first + (pos & 1 ? 0 : 1),
                             second + (pos & 1 ? 1 : 0)));
    ans = min(ans, 1 + solve(pos + 1, first, second));
  }
  return ans;
}
void run() {
  cin >> s;
  for (long long i = 0; i <= 10; i++)
    for (long long j = 0; j <= 10; j++)
      for (long long k = 0; k <= 10; k++) dp[i][j][k] = -1;
  cout << solve(0, 0, 0) << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie();
  long long t;
  cin >> t;
  while (t--) {
    run();
  }
}
