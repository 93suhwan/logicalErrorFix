#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int i, k = 0;
    for (i = 0; i < n; i++) {
      if (a[i] == '0' && b[i] == '1') {
        k += 2;
        continue;
      }
      if (a[i] == '1' && b[i] == '0') {
        k += 2;
        continue;
      }
      if (a[i] == '0' && b[i] == '0') {
        if (i < n - 1) {
          if (a[i + 1] == '1' && b[i + 1] == '1') {
            k += 2;
            i++;
            continue;
          } else {
            k++;
            continue;
          }
        } else {
          k++;
          continue;
        }
      }
      if (a[i] == '1' && b[i] == '1') {
        if (i < n - 1) {
          if (a[i + 1] == '0' && b[i + 1] == '0') {
            k += 2;
            i++;
            continue;
          }
        }
      }
    }
    cout << k << '\n';
  }
}
