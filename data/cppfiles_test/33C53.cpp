#include <bits/stdc++.h>
using namespace std;
int n, a[100005], dp[512];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 512; i++) {
    dp[i] = 512;
  }
  dp[0] = -1;
  for (int i = 0; i < n; i++) {
    dp[a[i]] = min(dp[a[i]], a[i]);
    for (int j = 0; j < 512; j++) {
      if (dp[j] >= a[i]) continue;
      dp[j ^ a[i]] = min(dp[j ^ a[i]], a[i]);
    }
  }
  int cnt = 0;
  for (int i = 0; i < 512; i++) {
    if (dp[i] < 512) cnt++;
  }
  cout << cnt << '\n';
  for (int i = 0; i < 512; i++) {
    if (dp[i] == 512) continue;
    cout << i << ' ';
  }
  cout << '\n';
  return 0;
}
