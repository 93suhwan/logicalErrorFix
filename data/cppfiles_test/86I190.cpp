#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int c[n];
    for (int i = 0; i < n; i++) {
      c[i] = (int(s1[i]) - 48) + (int(s2[i]) - 48);
    }
    int cnt = 0;
    int y = 5;
    for (int i = 0; i < n; i++) {
      if (c[i] == 1) {
        cnt = cnt + 2;
        y = 5;
      } else if (c[i] == 2) {
        if (y == 0) {
          cnt = cnt + 2;
          y = 5;
        } else {
          y = 2;
        }
      } else if (c[i] == 0) {
        if (y == 2) {
          cnt = cnt + 2;
          y = 5;
        } else {
          y = 0;
        }
      }
    }
    if (y == 0) {
      for (int i = n - 1; i >= 0; i--) {
        if (c[i] == 0) {
          cnt = cnt + 1;
        } else {
          break;
        }
      }
    }
    cout << cnt << endl;
  }
}
