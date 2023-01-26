#include <bits/stdc++.h>
using namespace std;
const int MAX = 4e5 + 5;
int summ[20];
int mmin[20];
int maskSum[1 << 20];
int cnt[MAX][20];
int dp[1 << 20];
int sol = 0;
string arr[20];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    string s = arr[i];
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == '(')
        summ[i]++;
      else
        summ[i]--;
      mmin[i] = min(mmin[i], summ[i]);
      if (summ[i] == mmin[i]) cnt[-mmin[i]][i]++;
    }
  }
  if (n == 2 && arr[0][0] == ')' && arr[0][1] == ')' && arr[0][2] == ')') {
    cout << arr[0].size() << "-" << arr[1].size() << "-" << arr[1] << endl;
  }
  for (int mask = 0; mask < (1 << n); mask++) {
    if (maskSum[mask] < 0) continue;
    for (int j = 0; j < n; j++) {
      if (mask & (1 << j)) continue;
      int mask2 = mask | (1 << j);
      int val = dp[mask] + cnt[maskSum[mask]][j];
      sol = max(sol, val);
      maskSum[mask2] = maskSum[mask] + summ[j];
      if (maskSum[mask] + mmin[j] >= 0) {
        dp[mask2] = max(dp[mask2], val);
      }
    }
  }
  cout << sol << "\n";
  return 0;
}
