#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    bool f = false;
    cin >> n;
    char a[n - 2][2];
    for (int i = 0; i < n - 2; i++) {
      cin >> a[i][0] >> a[i][1];
    }
    vector<char> ans;
    ans.push_back(a[0][0]);
    for (int i = 1; i < n - 2; i++) {
      if (a[i - 1][1] != a[i][0]) {
        f = true;
        ans.push_back(a[i - 1][1]);
      }
      ans.push_back(a[i][0]);
    }
    ans.push_back(a[n - 3][1]);
    if (f)
      for (int i = 0; i < n; i++) {
        cout << ans[i];
      }
    else {
      for (int i = 0; i < n - 1; i++) {
        cout << ans[i];
      }
      cout << ans[n - 2];
    }
    cout << endl;
  }
}
