#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e6 + 100;
void tmax(int& a, int b) { a = max(a, b); }
void tmin(int& a, int b) { a = min(a, b); }
int a[N];
int dp[N][2][2];
pair<int, int> fat[N][2][2];
int f(int a) {
  if (a == 1) return a;
  return a - 1;
}
void proc(int i, int b1, int b2, int b3, int b4) {
  if (dp[i - 1][b3][b4] == INF) return;
  if (b2 == b4) {
    if (a[i - 1] * f(b3) > a[i] * f(b1)) return;
    int adv;
    if (b2 == 1)
      adv = dp[i - 1][b3][b4];
    else
      adv = max(dp[i - 1][b3][b4], a[i] * f(b1));
    if (dp[i][b1][b2] > adv) {
      tmin(dp[i][b1][b2], adv);
      fat[i][b1][b2] = {b3, b4};
    }
  } else {
    if (dp[i - 1][b3][b4] > a[i] * f(b1)) return;
    int adv;
    if (b2 == 1)
      adv = a[i - 1] * f(b3);
    else
      adv = max(a[i - 1] * f(b3), a[i] * f(b1));
    if (dp[i][b1][b2] > adv) {
      tmin(dp[i][b1][b2], adv);
      fat[i][b1][b2] = {b3, b4};
    }
  }
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    dp[i][0][0] = dp[i][0][1] = INF;
    dp[i][1][0] = dp[i][1][1] = INF;
  }
  cin >> a[0];
  dp[0][0][0] = -a[0];
  dp[0][1][0] = a[0];
  dp[0][0][1] = dp[0][1][1] = -INF;
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    for (int b = 0; b < 16; b++) {
      int b1 = b & 1, b2 = (b >> 1) & 1, b3 = (b >> 2) & 1, b4 = (b >> 3) & 1;
      proc(i, b1, b2, b3, b4);
    }
  }
  if (dp[n - 1][1][0] == INF)
    cout << "NO" << '\n';
  else {
    vector<int> ans(n);
    int pos = n - 1, b1 = 1, b2 = 0;
    while (pos > 0) {
      ans[pos] = a[pos] * f(b1);
      int b3 = fat[pos][b1][b2].first;
      int b4 = fat[pos][b1][b2].second;
      b1 = b3;
      b2 = b4;
      pos--;
    }
    ans[pos] = a[pos] * f(b1);
    cout << "YES" << '\n';
    for (int x : ans) cout << x << " ";
    cout << '\n';
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
