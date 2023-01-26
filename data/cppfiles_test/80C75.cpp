#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string second;
    cin >> second;
    int len = n / 2;
    int l1 = -1, r1 = -1, l2 = -1, r2 = -1;
    for (int i = 0; i < n; i++) {
      if (second[i] == '0') {
        if (i >= len) {
          l1 = 1;
          r1 = i + 1;
          l2 = 1;
          r2 = i;
          break;
        }
      }
    }
    if (l1 == -1) {
      for (int i = n - 1; i >= 0; i--) {
        if (second[i] == '0') {
          if (n - i - 1 >= len) {
            l1 = i + 1;
            r1 = n;
            l2 = i + 2;
            r2 = n;
            break;
          }
        }
      }
    }
    if (l1 == -1) {
      l1 = 1;
      r1 = (n + 1) / 2;
      l2 = l1 + 1;
      r2 = r1 + 1;
    }
    cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
  }
  return 0;
}
