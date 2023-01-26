#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    vector<vector<int>> freq(n, vector<int>(5, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < arr[i].length(); ++j) {
        freq[i][arr[i][j] - 'a']++;
      }
    }
    int maxxy = 0;
    for (int i = 0; i < 5; ++i) {
      int64_t cur = 0, other = 0;
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < 5; ++k) {
          if (i == k) {
            cur += freq[j][k];
          } else
            other += freq[j][k];
        }
      }
      vector<pair<int, int>> ans;
      for (int j = 0; j < n; ++j) {
        ans.push_back({arr[j].length() - freq[j][i], freq[j][i]});
      }
      sort(ans.begin(), ans.end(), [&](pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
          return a.second > b.second;
        }
        return a.first < b.first;
      });
      while (!ans.empty() && cur <= other) {
        other -= ans.back().first;
        cur -= ans.back().second;
        ans.pop_back();
      }
      maxxy = max((int)ans.size(), maxxy);
    }
    cout << maxxy << endl;
  }
  return 0;
}
