#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
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
        cout << i + 1 << ' ' << j + 1 << ' ' << d << '\n';
      }
    }
  }
  return 0;
}
