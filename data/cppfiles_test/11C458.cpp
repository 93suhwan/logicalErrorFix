#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    vector<int> v[5];
    int a[n][5];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        a[i][j] = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < s[i].size(); j++) {
        a[i][s[i][j] - 'a']++;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        a[i][j] -= (s[i].size() - a[i][j]);
      }
    }
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < n; j++) {
        v[i].push_back(a[j][i]);
      }
    }
    for (int i = 0; i < 5; i++) {
      sort(v[i].begin(), v[i].end(), greater<int>());
    }
    int ans[5];
    for (int i = 0; i < 5; i++) {
      ans[i] = 0;
    }
    for (int i = 0; i < 5; i++) {
      int sz = 0;
      for (int j = 0; j < n; j++) {
        if (sz + v[i][j] > 0) {
          ans[i]++;
          sz += v[i][j];
        }
      }
    }
    int res = 0;
    for (int i = 0; i < 5; i++) {
      res = max(res, ans[i]);
    }
    cout << res << "\n";
  }
  return 0;
}
