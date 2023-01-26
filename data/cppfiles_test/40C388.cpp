#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<vector<int>> scale(2, vector<int>(n, 0));
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        cin >> scale[i][j];
      }
    }
    int i = 0;
    int j = n - 1;
    vector<long long> preSum(n + 1, 0);
    preSum[1] = scale[1][0];
    for (int i = 2; i <= n; i++) preSum[i] = preSum[i - 1] + scale[1][i - 1];
    vector<long long> back(n + 1, 0);
    back[n - 1] = scale[0][n - 1];
    for (int i = n - 2; i >= 0; i--) {
      back[i] = back[i + 1] + scale[0][i];
    }
    long long finalAns = INT_MAX;
    for (int i = 0; i < n; i++) {
      finalAns = min(finalAns, max(back[i + 1], preSum[i]));
    }
    cout << finalAns << endl;
  }
  return 0;
}
