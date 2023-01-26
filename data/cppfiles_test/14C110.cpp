#include <bits/stdc++.h>
using namespace std;
long long int dp[2005][2005];
void solve() {
  long long int n, k;
  cin >> n >> k;
  long long int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = -1;
    }
  }
  queue<pair<long long int, pair<long long int, long long int>>> pq;
  pq.push({0, {0, 0}});
  while (!pq.empty()) {
    pair<long long int, pair<long long int, long long int>> p = pq.front();
    pq.pop();
    long long int index = p.second.first;
    long long int move = p.second.second;
    long long int good = p.first;
    if (index > n) {
      continue;
    }
    if (dp[index][move] > good) {
      continue;
    }
    long long int x = good;
    dp[index][move] = good;
    if (arr[index] == index - move + 1) {
      x++;
    }
    if (dp[index + 1][move] < x) {
      dp[index + 1][move] = x;
      pq.push({x, {index + 1, move}});
    }
    if (dp[index + 1][move + 1] < good) {
      dp[index + 1][move + 1] = good;
      pq.push({good, {index + 1, move + 1}});
    }
  }
  long long int ans = INT_MAX;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (dp[i][j] >= k) {
        ans = min(ans, (long long int)j);
      }
    }
  }
  if (ans == INT_MAX) {
    ans = -1;
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
