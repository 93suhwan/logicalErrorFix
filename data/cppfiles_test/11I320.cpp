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
    int ans = 0;
    for (int i = 0; i < 5; i++) {
      vector<pair<int, int>> temp;
      int cnt1 = 0, cnt2 = 0;
      for (int j = 0; j < n; j++) {
        int countthis = 0;
        int countothers = 0;
        for (auto c : words[j]) {
          if ((c - 'a') == i)
            countthis++;
          else
            countothers++;
        }
        cnt1 += countthis;
        cnt2 += countothers;
        temp.push_back({countthis, countothers});
      }
      int includes = n;
      if (cnt1 > cnt2) {
        ans = max(ans, includes);
        break;
      }
      sort(temp.begin(), temp.end(), [&](pair<int, int>& a, pair<int, int>& b) {
        if (a.second == b.second) {
          return a.first < b.first;
        }
        return a.second > b.second;
      });
      for (int j = 0; j < n; j++) {
        includes--;
        cnt1 -= temp[j].first;
        cnt2 -= temp[j].second;
        if (cnt1 > cnt2) {
          break;
        }
      }
      if (cnt1 > cnt2) ans = max(ans, includes);
    }
    cout << ans << endl;
  }
}
