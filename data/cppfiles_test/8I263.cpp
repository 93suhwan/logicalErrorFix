#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int count = 0;
  vector<int> ans;
  for (int i = 0; i < t; i++) {
    int num;
    cin >> num;
    while (num > 0) {
      int num1 = round((float)num / 3);
      int num2 = num - 2 * num1;
      ans.push_back(num2);
      ans.push_back(num1);
      num = 0;
    }
  }
  for (int i = 0; i < ans.size(); i = i + 2)
    cout << ans[i] << " " << ans[i + 1] << "\n";
  return 0;
}
