#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n], max = -1;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] > max) max = a[i];
    }
    int c = 0, k = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] > k) {
        k = a[i];
        c++;
      }
    }
    cout << c << "\n";
  }
  return 0;
}
