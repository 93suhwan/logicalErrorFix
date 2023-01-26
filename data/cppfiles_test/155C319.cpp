#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  string s;
  cin >> s;
  int ans[n];
  int count = 0;
  vector<pair<int, int>> dislike;
  vector<pair<int, int>> like;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '0') count++;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      dislike.emplace_back(a[i], i);
    } else {
      like.emplace_back(a[i], i);
    }
  }
  sort(dislike.begin(), dislike.end());
  sort(like.begin(), like.end());
  for (auto itr : like) {
  }
  int temp = 1;
  for (auto itr : dislike) {
    ans[itr.second] = temp;
    temp++;
  }
  count++;
  for (auto itr : like) {
    ans[itr.second] = count;
    count++;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
