#include <bits/stdc++.h>
using namespace std;
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  init_code();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
      cin >> words[i];
    }
    vector<vector<vector<int>>> v(5, vector<vector<int>>(2, vector<int>(n, 0)));
    for (int i = 0; i < n; i++) {
      for (auto c : words[i]) {
        v[c - 'a'][0][i]++;
      }
      for (int j = 0; j < 5; j++) {
        v[j][1][i] = words[i].size() - v[j][0][i];
      }
    }
    int ans = 0;
    for (int i = 0; i < 5; i++) {
      int countthis = 0;
      int countothers = 0;
      int curr = n;
      vector<pair<int, int>> temp;
      for (int j = 0; j < n; j++) {
        temp.push_back({v[i][0][j], v[i][1][j]});
      }
      sort(temp.begin(), temp.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
      });
      for (int j = 0; j < n; j++) {
        countthis += temp[j].first;
        countothers += temp[j].second;
      }
      for (int j = 0; j < n; j++) {
        if (countthis > countothers) {
          break;
        }
        countthis -= temp[j].first;
        countothers -= temp[j].second;
        curr--;
      }
      ans = max(ans, curr);
    }
    cout << ans << endl;
  }
}
