#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> v(n - 2);
    string res;
    for (int i = 0; i < n - 2; i++) {
      string s;
      cin >> s;
      v[i] = s;
    }
    bool flag = false;
    res = v[0];
    for (int i = 1; i <= n - 3; i++) {
      if (flag == false && v[i - 1][1] != v[i][0]) {
        res = res + v[i][0];
        flag = true;
      }
      res = res + v[i][1];
    }
    if (!flag) {
      res = res + v[n - 3][1];
    }
    cout << res << endl;
  }
  return 0;
}
