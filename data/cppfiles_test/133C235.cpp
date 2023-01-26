#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    n -= 2;
    vector<string> a;
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      a.push_back(s);
    }
    bool flag = 1;
    for (int i = 0; i < a.size() - 1; ++i) {
      if (a[i][1] != a[i + 1][0]) flag = 0;
    }
    if (flag) {
      cout << a[0];
      for (int i = 1; i < a.size(); ++i) cout << a[i][1];
      cout << a[a.size() - 1][1];
    } else {
      cout << a[0];
      for (int i = 1; i < a.size(); ++i) {
        if (a[i - 1][1] != a[i][0]) {
          cout << a[i];
        } else
          cout << a[i][1];
      }
    }
    cout << "\n";
  }
}
