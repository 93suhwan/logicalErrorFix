#include <bits/stdc++.h>
using namespace std;
int T;
int n, a[100005], b[100005];
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    if (n % 2 == 0) {
      for (int i = 1; i <= n; i += 2) {
        b[i] = a[i + 1];
        b[i + 1] = -a[i];
      }
    } else {
      for (int i = 4; i <= n; i += 2) {
        b[i] = a[i + 1];
        b[i + 1] = -a[i];
      }
      if (a[1] + a[2] != 0) {
        b[1] = b[2] = -a[3];
        b[3] = a[1] + a[2];
      } else if (a[1] + a[3] != 0) {
        b[1] = b[3] = -a[2];
        b[2] = a[1] + a[3];
      } else if (a[2] + a[3] != 0) {
        b[3] = b[2] = -a[1];
        b[1] = a[3] + a[2];
      }
    }
    for (int i = 1; i <= n; i++) cout << b[i] << " ";
    cout << endl;
  }
}
