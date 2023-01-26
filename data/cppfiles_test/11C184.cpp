#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(5));
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      vector<int> cnt(5, 0);
      for (int j = 0; j < s.length(); ++j) cnt[s[j] - 'a']++;
      for (int j = 0; j < 5; j++) arr[i][j] = cnt[j] - (s.length() - cnt[j]);
    }
    int maxxy = 0;
    for (int i = 0; i < 5; i++) {
      int cnt = 0, curr = 0;
      vector<int> ans(n);
      for (int j = 0; j < n; j++) {
        ans[j] = arr[j][i];
      }
      sort(ans.rbegin(), ans.rend());
      for (int j = 0; j < n; j++) {
        if (curr + ans[j] > 0) {
          cnt++, curr += ans[j];
        }
      }
      maxxy = max(maxxy, cnt);
    }
    cout << maxxy << "\n";
  }
  return 0;
}
