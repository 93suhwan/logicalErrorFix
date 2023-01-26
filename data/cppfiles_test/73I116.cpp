#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 0; i < n; i++) {
      cin >> a[i + 1];
    }
    int i = 1;
    bool flag = true;
    while (flag) {
      int c = 0;
      if (i % 2 == 0) {
        for (int j = 2; j < n; j = j + 2) {
          if (a[j] > a[j + 1]) {
            int temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
            c++;
          }
        }
      } else {
        for (int j = 1; j < n; j = j + 2) {
          if (a[j] > a[j + 1]) {
            int temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
            c++;
          }
        }
      }
      if (c > 0) {
        i++;
      } else {
        flag = false;
      }
    }
    cout << (i - 1) << endl;
  }
  return 0;
}
