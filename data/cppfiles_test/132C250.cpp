#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int a[7];
    for (int i = 0; i < 7; i++) {
      cin >> a[i];
    }
    vector<int> ans;
    ans.push_back(a[0]);
    ans.push_back(a[1]);
    ans.push_back(a[6] - a[0] - a[1]);
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
  }
  return 0;
}
