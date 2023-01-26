#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> lengths;
    vector<vector<int>> ct(n, vector<int>(26, 0));
    for (int word = 0; word < n; word++) {
      string w;
      cin >> w;
      for (int i = 0; i < w.size(); i++) {
        ct[word][w.at(i) - 'a']++;
      }
      lengths.push_back(w.size());
    }
    int ans = 0;
    for (int letter = 0; letter < 26; letter++) {
      vector<int> curr;
      for (int i = 0; i < n; i++) {
        curr.push_back(lengths[i] - (2 * ct[i][letter]));
      }
      sort(curr.begin(), curr.end());
      int curr_max = 0;
      int sum = 0;
      for (int i = 0; i < curr.size(); i++) {
        sum += curr[i];
        if (sum < 0) {
          curr_max = i + 1;
        }
      }
      ans = max(ans, curr_max);
    }
    cout << ans << "\n";
  }
}
