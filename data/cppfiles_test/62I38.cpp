#include <bits/stdc++.h>
using namespace std;
long long int arr[1001][1001];
long long int dp[1001][1001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) arr[i][j] = 0, dp[i][j] = 0;
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      long long int r = i, c = j;
      long long int cnt = 0;
      while (r >= 1 && c >= 1) {
        arr[r][c]++;
        if (cnt % 2)
          r--;
        else
          c--;
        cnt++;
      }
      cnt = 0;
      r = i, c = j;
      while (r >= 1 && c >= 1) {
        arr[r][c]++;
        if (cnt % 2)
          c--;
        else
          r--;
        cnt++;
      }
    }
  }
  long long int sum = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      arr[i][j]--;
      sum += arr[i][j];
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  cout << sum << endl;
  while (q--) {
    long long int x, y;
    cin >> x >> y;
    long long int r = x, c = y;
    if (dp[r][c] == 0) {
      long long int temp = 0;
      long long int cnt = 0;
      while (r <= n && c <= m && dp[r][c] == 0) {
        temp++;
        if (cnt % 2 == 0)
          r++;
        else
          c++;
        cnt++;
      }
      r = x, c = y;
      cnt = 0;
      while (r >= 1 && c >= 1 && dp[r][c] == 0) {
        arr[r][c] -= temp;
        sum -= temp;
        if (cnt % 2 == 0)
          c--;
        else
          r--;
        cnt++;
      }
      temp = 0;
      cnt = 0;
      r = x, c = y;
      while (r <= n && c <= m && dp[r][c] == 0) {
        temp++;
        if (cnt % 2 == 0)
          c++;
        else
          r++;
        cnt++;
      }
      r = x, c = y;
      cnt = 0;
      while (r >= 1 && c >= 1 && dp[r][c] == 0) {
        arr[r][c] -= temp;
        sum -= temp;
        if (cnt % 2 == 0)
          r--;
        else
          c--;
        cnt++;
      }
      arr[x][y]++;
      sum += 1;
      dp[x][y] = 1;
      cout << sum << endl;
    } else {
      dp[x][y] = 0;
      long long int temp = 0;
      long long int cnt = 0;
      while (r <= n && c <= m && dp[r][c] == 0) {
        temp++;
        if (cnt % 2 == 0)
          r++;
        else
          c++;
        cnt++;
      }
      r = x, c = y;
      cnt = 0;
      while (r >= 1 && c >= 1 && dp[r][c] == 0) {
        arr[r][c] += temp;
        sum += temp;
        if (cnt % 2 == 0)
          c--;
        else
          r--;
        cnt++;
      }
      temp = 0;
      cnt = 0;
      r = x, c = y;
      while (r <= n && c <= m && dp[r][c] == 0) {
        temp++;
        if (cnt % 2 == 0)
          c++;
        else
          r++;
        cnt++;
      }
      r = x, c = y;
      cnt = 0;
      while (r >= 1 && c >= 1 && dp[r][c] == 0) {
        arr[r][c] += temp;
        sum += temp;
        if (cnt % 2 == 0)
          r--;
        else
          c--;
        cnt++;
      }
      arr[x][y]--;
      sum -= 1;
      cout << sum << endl;
    }
  }
}
