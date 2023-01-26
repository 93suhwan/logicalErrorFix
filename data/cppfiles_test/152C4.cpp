#include <bits/stdc++.h>
using namespace std;
int cas;
int arr[2000005];
int dp[2000005][2][2];
int casio[2000005][2][2];
int f(int i, int flag, int sgn) {
  if (i == 0) return -10000000;
  int cur = arr[i];
  if (sgn) cur *= -1;
  int ret = 10000000;
  if (casio[i][flag][sgn] == cas) return dp[i][flag][sgn];
  casio[i][flag][sgn] = cas;
  if (flag) {
    int pre = arr[i - 1];
    int a = f(i - 1, 0, 0);
    if (cur > pre && cur > a) ret = min(ret, pre);
    a = f(i - 1, 1, 0);
    if (cur > pre && cur > a) ret = min(ret, a);
    pre *= -1;
    a = f(i - 1, 0, 1);
    if (cur > pre && cur > a) ret = min(ret, pre);
    a = f(i - 1, 1, 1);
    if (cur > pre && cur > a) ret = min(ret, a);
  } else {
    int pre = arr[i - 1];
    int a = f(i - 1, 0, 0);
    if (cur > pre && cur < a) ret = min(ret, a);
    a = f(i - 1, 1, 0);
    if (cur < pre && cur > a) ret = min(ret, pre);
    pre *= -1;
    a = f(i - 1, 0, 1);
    if (cur > pre && cur < a) ret = min(ret, a);
    a = f(i - 1, 1, 1);
    if (cur < pre && cur > a) ret = min(ret, pre);
  }
  return dp[i][flag][sgn] = ret;
}
void dfs(int i, int flag, int sgn) {
  if (sgn) arr[i] *= -1;
  if (i == 0) return;
  int cur = arr[i];
  int ret = f(i, flag, sgn);
  if (flag) {
    int pre = arr[i - 1];
    int a = f(i - 1, 0, 0);
    if (cur > pre && cur > a && ret == pre) {
      dfs(i - 1, 0, 0);
      return;
    }
    a = f(i - 1, 1, 0);
    if (cur > pre && cur > a && ret == a) {
      dfs(i - 1, 1, 0);
      return;
    }
    pre *= -1;
    a = f(i - 1, 0, 1);
    if (cur > pre && cur > a && ret == pre) {
      dfs(i - 1, 0, 1);
      return;
    }
    a = f(i - 1, 1, 1);
    if (cur > pre && cur > a && ret == a) {
      dfs(i - 1, 1, 1);
      return;
    }
  } else {
    int pre = arr[i - 1];
    int a = f(i - 1, 0, 0);
    if (cur > pre && cur < a && ret == a) {
      dfs(i - 1, 0, 0);
      return;
    }
    a = f(i - 1, 1, 0);
    if (cur < pre && cur > a && ret == pre) {
      dfs(i - 1, 1, 0);
    }
    pre *= -1;
    a = f(i - 1, 0, 1);
    if (cur > pre && cur < a && ret == a) {
      dfs(i - 1, 0, 1);
      return;
    }
    a = f(i - 1, 1, 1);
    if (cur < pre && cur > a && ret == pre) {
      dfs(i - 1, 1, 1);
      return;
    }
  }
}
void solve() {
  cas++;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  if (f(n - 1, 0, 0) <= n)
    dfs(n - 1, 0, 0);
  else if (f(n - 1, 0, 1) <= n)
    dfs(n - 1, 0, 1);
  else if (f(n - 1, 1, 0) <= n)
    dfs(n - 1, 1, 0);
  else if (f(n - 1, 1, 1) <= n)
    dfs(n - 1, 1, 1);
  else {
    cout << "NO" << '\n';
    return;
  }
  cout << "YES" << '\n';
  for (int i = 0; i < n; i++) cout << arr[i] << ' ';
  cout << '\n';
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
