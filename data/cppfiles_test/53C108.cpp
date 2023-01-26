#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    char c;
    cin >> c;
    string s;
    cin >> s;
    bool m = 1;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (s[i] != c) {
        m = 0;
      }
    }
    if (m == 1) {
      cout << 0 << endl;
    } else {
      for (int i = 1; i < n + 1; i++) {
        m = true;
        for (int j = i; j < n + 1; j++) {
          m &= (s[j - 1] == c);
          j += i - 1;
        }
        if (m) {
          ans.push_back(i);
          break;
        }
      }
      if (!m) {
        ans.push_back(n);
        ans.push_back(n - 1);
      }
      cout << ans.size() << endl;
      for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
      }
      cout << endl;
    }
  }
}
