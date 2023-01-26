#include <bits/stdc++.h>
using namespace std;
const long long INFLL = LLONG_MAX;
const int INF = INT_MAX;
const long long MAXLL = 0x3f3f3f3f3f3f3f3f;
const int MAX = 0x3f3f3f3f;
const long long MOD = 1000000007;
const long long mod = 998244353;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
void sort(vector<T>& v) {
  sort(v.begin(), v.end());
}
template <class T, class U>
void sort(vector<T>& v, U func) {
  sort(v.begin(), v.end(), func);
}
template <class T>
void rsort(vector<T>& v) {
  sort(v.rbegin(), v.rend());
}
template <class T>
int lb_index(vector<T>& v, T k) {
  return lower_bound(v.begin(), v.end(), k) - v.begin();
}
template <class T>
int ub_index(vector<T>& v, T k) {
  return upper_bound(v.begin(), v.end(), k) - v.begin();
}
template <class T>
bool is_sorted(vector<T>& v) {
  return is_sorted(v.begin(), v.end());
}
template <class T>
bool sorted(vector<T>& v) {
  return is_sorted(v);
}
void precompute() { return; }
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  reverse(s.begin(), s.end());
  vector<vector<vector<long long>>> dp(
      n, vector<vector<long long>>(4, vector<long long>(10)));
  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j <= 9; j++) {
      if (i + j < 10) {
        dp[0][0][i + j]++;
      } else {
        dp[0][2][i + j - 10]++;
      }
    }
  }
  for (int k = 1; k < n; k++) {
    for (int i = 0; i < 10; i++) {
      dp[k][0][i] =
          dp[k - 1][0][s[k - 1] - '0'] * dp[0][0][i] +
          dp[k - 1][1][s[k - 1] - '0'] * (i > 0 ? dp[0][0][i - 1] : 0);
      dp[k][1][i] =
          dp[k - 1][2][s[k - 1] - '0'] * dp[0][0][i] +
          dp[k - 1][3][s[k - 1] - '0'] * (i > 0 ? dp[0][0][i - 1] : 0);
      dp[k][2][i] =
          dp[k - 1][0][s[k - 1] - '0'] * dp[0][2][i] +
          dp[k - 1][1][s[k - 1] - '0'] * (i > 0 ? dp[0][2][i - 1] : 0);
      dp[k][3][i] =
          dp[k - 1][2][s[k - 1] - '0'] * dp[0][2][i] +
          dp[k - 1][3][s[k - 1] - '0'] * (i > 0 ? dp[0][2][i - 1] : 0);
    }
  }
  cout << dp[n - 1][0][s[n - 1] - '0'] << "\n";
  return;
}
int main() {
  ios::sync_with_stdio(0);
  int numberofsubtestcases = 1;
  cin >> numberofsubtestcases;
  precompute();
  for (int looping = 1; looping <= numberofsubtestcases; looping++) {
    solve();
  }
  return 0;
}
