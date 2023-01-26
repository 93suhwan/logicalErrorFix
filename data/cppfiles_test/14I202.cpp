#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> b(3);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
      int d = 0, j;
      bool m = false;
      for (j = i + 1; j < n; j++) {
        if (a[i] >= a[j]) m = true, d = 1;
        if (j + 1 < n && a[j + 1] <= a[j] && m == true)
          d++;
        else if (m == true)
          break;
      }
      vector<int> tmp;
      if (d > 0) {
        for (int o = j - d + 1; o <= j; o++) {
          tmp.push_back(a[o]);
        }
        for (int o = i; o <= j - d; o++) {
          tmp.push_back(a[o]);
        }
        for (int o = i; o <= j; o++) {
          a[o] = tmp[o - i];
        }
        b[0].push_back(i + 1);
        b[1].push_back(j + 1);
        b[2].push_back(d);
      }
    }
    cout << b[0].size() << '\n';
    for (int i = 0; i < b[0].size(); i++) {
      cout << b[0][i] << ' ' << b[1][i] << ' ' << b[1][i] - b[2][i] << '\n';
    }
  }
  return 0;
}
