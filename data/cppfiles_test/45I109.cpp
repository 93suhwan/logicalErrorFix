#include <bits/stdc++.h>
using namespace std;
int t;
long long k = 1;
int n;
int a[105];
int main() {
  cin >> t;
  while (t--) {
    k = 1;
    cin >> n;
    cin >> a[1];
    if (a[1] == 1) k += 1;
    for (int i = 2; i <= n; i++) {
      cin >> a[i];
      if (a[i - 1] == 0 && a[i] == 0) {
        k = -1;
        break;
      }
      if (a[i - 1] == 1 && a[i] == 1) {
        k += 5;
        continue;
      }
      if (a[i - 1] == 0 && a[i] == 1) {
        k += 1;
        continue;
      }
    }
    cout << k << endl;
  }
  return 0;
}
