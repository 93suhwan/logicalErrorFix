#include <bits/stdc++.h>
using namespace std;
void solve() {
  vector<int> t(7);
  vector<int> ans(3);
  for (int i = 0; i < 7; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < 3; i++) {
    ans[i] = t[i];
  }
  int cnt = 0;
  int wh = 3;
  while (cnt < 7) {
    vector<int> czy;
    czy.push_back(ans[0]);
    czy.push_back(ans[1]);
    czy.push_back(ans[2]);
    czy.push_back(ans[0] + ans[1]);
    czy.push_back(ans[0] + ans[2]);
    czy.push_back(ans[1] + ans[2]);
    czy.push_back(ans[0] + ans[1] + ans[2]);
    sort(czy.begin(), czy.end());
    cnt = 0;
    for (int i = 0; i < 7; i++) {
      if (t[i] == czy[i]) cnt++;
    }
    if (cnt == 7) {
      for (int i = 0; i < 3; i++) {
        cout << ans[i] << " ";
      }
      cout << "\n";
      break;
    }
    ans.erase(ans.begin() + 2);
    ans.push_back(t[wh]);
    wh++;
    for (int i = 0; i < 7; i++) {
      czy.pop_back();
    }
  }
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
