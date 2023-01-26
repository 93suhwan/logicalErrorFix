#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t, n, i, j, k, l;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<string> vect;
    vector<long long> let[5];
    for (i = 0; i < n; i++) {
      string str;
      cin >> str;
      vect.push_back(str);
      vector<long long> cnt(5, 0);
      for (j = 0; j < str.size(); j++) {
        cnt[str[j] - 'a']++;
      }
      for (j = 0; j < 5; j++) {
        let[j].push_back(str.size() - 2 * cnt[j]);
      }
    }
    for (i = 0; i < 5; i++) sort(let[i].begin(), let[i].end());
    long long ans = 0;
    for (i = 0; i < 5; i++) {
      for (j = 1; j < let[i].size(); j++) {
        let[i][j] += let[i][j - 1];
      }
      for (j = 0; j < let[i].size(); j++) {
        if (let[i][j] < 0) ans = max(ans, j + 1);
      }
    }
    cout << ans << endl;
  }
}
