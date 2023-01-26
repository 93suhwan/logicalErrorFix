#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &it : v) is >> it;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << '{';
  string sep = "";
  for (const auto &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
void dbg_out() { cerr << " end.\n"; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << H << ' ';
  dbg_out(T...);
}
const int N = 2e3 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int dp[N];
int arr[N];
void solve(int T) {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    dp[i] = -1;
    cin >> arr[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j >= 1; --j) {
      dp[j] = max(dp[j], dp[j - 1] + (arr[i] == j));
    }
  }
  for (int i = n; i >= 1; --i) {
    if (dp[i] >= k) {
      cout << n - i << "\n";
      return;
    }
  }
  cout << "-1\n";
}
int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t;
  cin >> t;
  for (int tt = 0; tt < t; ++tt) solve(1);
  return 0;
}
