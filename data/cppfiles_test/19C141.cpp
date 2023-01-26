#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>& segs) {
  int MAX_LEN = (*max_element(segs.begin(), segs.end()) * 2);
  vector<vector<int> > dp(segs.size() + 1, vector<int>(MAX_LEN, 500000));
  dp[0][0] = 0;
  for (int(i) = (0); (i) < (segs.size()); ++(i)) {
    for (int(l) = (0); (l) < (MAX_LEN); ++(l)) {
      if (dp[i][l] >= 500000) continue;
      dp[i + 1][max(l - segs[i], 0)] =
          min(dp[i + 1][max(l - segs[i], 0)], dp[i][l] + segs[i]);
      if (l + segs[i] < MAX_LEN)
        dp[i + 1][l + segs[i]] =
            min(dp[i + 1][l + segs[i]], max(dp[i][l] - segs[i], 0));
    }
  }
  int ret = INT_MAX;
  for (int(l) = (0); (l) < (MAX_LEN); ++(l)) {
    ret = min(ret, dp[segs.size()][l] + l);
  }
  return ret;
}
int T, N;
int main() {
  cin >> T;
  for (int(i) = (0); (i) < (T); ++(i)) {
    cin >> N;
    vector<int> segments(N);
    for (int(i) = (0); (i) < (N); ++(i)) {
      cin >> segments[i];
    }
    cout << solve(segments) << endl;
  }
  return 0;
}
