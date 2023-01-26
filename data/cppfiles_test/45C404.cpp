#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int height = 1;
    if (a[0] == 1) {
      height++;
    }
    for (int i = 1; i < n; i++) {
      if (a[i - 1] & a[i]) {
        height += 5;
      } else if (a[i] == 1) {
        height += 1;
      } else if (a[i - 1] == 0 & a[i] == 0) {
        height = -1;
        break;
      }
    }
    cout << height << endl;
  }
}
