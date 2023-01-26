#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  vector<int> ans;
  vector<int> a;
  for (int i = 0; i < t; i++) {
    int z;
    cin >> z;
    if (z % 3 != 0 && z % 10 != 3) {
      ans.push_back(z);
    } else {
      a.push_back(z);
    }
  }
  int x = ans.size() + 1;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] + x << endl;
    x++;
  }
  return 0;
}
