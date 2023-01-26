#include <bits/stdc++.h>
using namespace std;
int main() {
  long long T, n;
  cin >> T;
  string ans = "";
  while (T--) {
    cin >> n;
    ans = "";
    vector<string> nums(n - 2), ans;
    for (int i = 0; i < n - 2; i++) cin >> nums[i];
    ans.push_back(nums[0]);
    for (int i = 1; i < n - 2; i++) {
      if (nums[i][0] != nums[i - 1][1]) {
        string t = "";
        t.push_back(nums[i - 1][1]);
        t.push_back(nums[i][0]);
        ans.push_back(t);
      }
      ans.push_back(nums[i]);
    }
    if (ans.size() == n - 2) {
      string t = "";
      char ch = ans.back()[1];
      t.push_back(ch);
      t.push_back(ch);
      ans.push_back(t);
    }
    for (int i = 0; i < ans.size(); i++) {
      if (i == ans.size() - 1)
        cout << ans[i];
      else
        cout << ans[i][0];
    }
    cout << endl;
  }
  return 0;
}
