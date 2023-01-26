#include <bits/stdc++.h>
using namespace std;
void solve() {
  int leval;
  cin >> leval;
  vector<pair<int, int>> vp;
  for (int i = 0; i < leval; i++) {
    int caves;
    cin >> caves;
    int startPower = INT_MIN;
    for (int j = 0; j < caves; j++) {
      int cave;
      cin >> cave;
      startPower = max(startPower, cave - j);
    }
    vp.push_back(make_pair(startPower + 1, caves));
  }
  sort(vp.begin(), vp.end());
  int res = vp[0].first, doneCave = vp[0].second;
  for (int i = 1; i < vp.size(); i++) {
    if (res + doneCave <= vp[i].first) res = vp[i].first - doneCave;
    doneCave += vp[i].second;
  }
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
