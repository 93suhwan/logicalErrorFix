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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool sortm(pair<int, int> &a, pair<int, int> &b) {
  int x = abs(a.first) + abs(a.second);
  int y = abs(b.first) + abs(b.second);
  return x < y;
}
void init() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
vector<int> a(1005);
int dp[1001][1001];
int n, k;
void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n; j++) {
      if (a[i] == (i - j + 1))
        dp[i][j] = 1 + (i == 0 ? 0 : dp[i - 1][j]);
      else {
        if (i == 0)
          dp[i][j] = 0;
        else
          dp[i][j] = dp[i - 1][j];
        if (a[i] <= (i - j + 1) && i > 0) {
          int jj = (i + 1 - j - a[i]);
          if (j - jj >= 0)
            dp[i][j] = max(dp[i][j], dp[i - 1][j - (i + 1 - j - a[i])]);
        }
      }
    }
  }
  int ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n; j++) {
      if (dp[i][j] >= k) {
        ans = min(ans, j);
      }
    }
  }
  cout << (ans == INT_MAX ? -1 : ans) << "\n";
  return;
}
int main() {
  init();
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
