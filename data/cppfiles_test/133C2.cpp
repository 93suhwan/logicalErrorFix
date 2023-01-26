#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a[n - 2];
    for (int i = 0; i < n - 2; i++) {
      cin >> a[i];
    }
    int j = -1;
    for (int i = 0; i < n - 3; i++) {
      if (a[i][1] != a[i + 1][0]) {
        j = i;
        break;
      }
    }
    if (j == -1) {
      cout << a[0];
      for (int i = 1; i < n - 2; i++) {
        cout << a[i][1];
      }
      cout << "b" << '\n';
    } else {
      for (int i = 0; i < n - 2; i++) {
        if (i == j) {
          cout << a[i];
        } else if (i == n - 3) {
          cout << a[i];
        } else {
          cout << a[i][0];
        }
      }
      cout << '\n';
    }
  }
  return 0;
}
