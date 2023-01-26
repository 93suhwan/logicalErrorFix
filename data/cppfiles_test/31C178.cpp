#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int i = 0, j = n - 1;
    if (n % 2 == 1) {
      if (a[i] + a[i + 1] != 0) {
        b[i] = -a[j];
        b[i + 1] = -a[j];
        b[j] = a[i] + a[i + 1];
      } else if (a[i] + a[j] != 0) {
        b[i] = -a[i + 1];
        b[j] = -a[i + 1];
        b[i + 1] = a[j] + a[i];
      } else {
        b[i + 1] = -a[i];
        b[j] = -a[i];
        b[i] = a[j] + a[i + 1];
      }
      i += 2;
      j--;
    }
    while (i < j) {
      b[i] = -1 * a[j];
      b[j] = a[i];
      i++;
      j--;
    }
    for (i = 0; i < n; i++) {
      cout << b[i] << " ";
    }
    cout << endl;
  }
}
