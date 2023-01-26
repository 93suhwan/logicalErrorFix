#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int count;
    bool isans = false;
    for (int i = 0; i < n; i++) {
      int flag = 0;
      if (a[0] % a[i] == 0)
        count = 0;
      else
        count = 1;
      for (int j = 1; j < n; j++) {
        if (count == 0 && a[j] % a[i] != 0) {
          count = 1;
        } else if (count == 1 && a[j] % a[i] == 0) {
          count = 0;
        } else {
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
        cout << a[i] << endl;
        isans = true;
        break;
      }
    }
    if (isans == false) cout << 0 << endl;
  }
}
