#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ar[n + 1];
    for (int i = 1; i <= n; i++) {
      cin >> ar[i];
    }
    int cnt = 1;
    for (cnt = 1; cnt <= n - 1; cnt++) {
      if (cnt & 1) {
        for (int i = 1; i <= n - 2; i += 2) {
          if (ar[i] > ar[i + 1]) {
            int tmp = ar[i];
            ar[i] = ar[i + 1];
            ar[i + 1] = tmp;
          }
        }
      } else {
        for (int i = 2; i <= n - 1; i += 2) {
          if (ar[i] > ar[i + 1]) {
            int tmp = ar[i];
            ar[i] = ar[i + 1];
            ar[i + 1] = tmp;
          }
        }
      }
      bool flag = true;
      for (int i = 1; i <= n; i++) {
        if (ar[i] != i) {
          flag = false;
          break;
        }
      }
      if (flag) {
        break;
      }
    }
    if (cnt == 1) {
      cout << "0" << endl;
    } else
      cout << cnt << endl;
  }
}
