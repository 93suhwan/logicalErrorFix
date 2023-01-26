#include <bits/stdc++.h>
using namespace std;
long long int GCD(long long int x, long long int y) {
  if (y == 0) return x;
  return GCD(y, x % y);
}
vector<bool> seive_Of_Eratosthenes(long long int n) {
  vector<bool> prime(n + 1, true);
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) {
        prime[i] = false;
      }
    }
  }
  return prime;
}
long long int power(long long int x, long long int y) {
  long long int ans = 1;
  while (y > 0) {
    if (y % 2 == 1) {
      ans = ans * x;
    }
    y = (y >> 1);
    x = x * x;
  }
  return ans;
}
int n, m, k;
int arr[1005][1005];
int dp[1005][1005][4];
int solve(int i, int j, int val) {
  if (i >= n) {
    return j;
  }
  if (dp[i][j][val] != -1) {
    return dp[i][j][val];
  }
  if (val == 1) {
    int data = arr[i][j + 1];
    arr[i][j] = 2;
    return dp[i][j][val] = solve(i, j + 1, data);
  } else if (val == 2) {
    int data = arr[i + 1][j];
    arr[i][j] = 2;
    return dp[i][j][val] = solve(i + 1, j, data);
  }
  int data = arr[i][j - 1];
  arr[i][j] = 2;
  return dp[i][j][val] = solve(i, j - 1, data);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  memset(dp, -1, sizeof(dp));
  vector<int> drop(k);
  for (int i = 0; i < k; i++) {
    cin >> drop[i];
    --drop[i];
  }
  vector<int> ans;
  for (int i = 0; i < k; i++) {
    cout << 1 + solve(0, drop[i], arr[0][drop[i]]) << " ";
  }
  return 0;
}
