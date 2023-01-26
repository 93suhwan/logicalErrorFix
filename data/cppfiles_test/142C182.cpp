#include <bits/stdc++.h>
using namespace std;
void file_i_o() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void _testCase() {
  int n, m;
  cin >> m >> n;
  vector<vector<int>> arr(m + 1, vector<int>(n + 1, 0));
  vector<int> max_val(n + 1, 0);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> arr[i][j];
      if (arr[i][j] > max_val[j]) max_val[j] = arr[i][j];
    }
  }
  int ans = max_val[1];
  for (int i = 2; i <= n; i++) ans = min(ans, max_val[i]);
  if (m <= n - 1)
    cout << ans << "\n";
  else {
    int val = 0;
    for (int i = 1; i <= m; ++i) {
      sort(arr[i].begin(), arr[i].end());
      val = max(val, arr[i][n - 1]);
    }
    ans = min(ans, val);
    cout << ans << "\n";
  }
}
int main(int argc, char const *argv[]) {
  clock_t time_req = clock();
  file_i_o();
  int t;
  cin >> t;
  while (t--) {
    _testCase();
  }
  return 0;
}
