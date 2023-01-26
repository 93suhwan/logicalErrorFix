#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
  vector<int> ans;
  int i = 1;
  int j = 0;
  while (j < 1000) {
    if (i % 3 != 0 && i % 10 != 3) ans.push_back(i), j++;
    i++;
  }
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    cout << ans[k - 1] << "\n";
  }
  return 0;
}
