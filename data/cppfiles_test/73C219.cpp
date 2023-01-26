#include <bits/stdc++.h>
using namespace std;
bool fun(int a[], int n) {
  for (int i = 1; i <= n; i++) {
    if (a[i] != i) return true;
  }
  return false;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    while (fun(a, n)) {
      ans++;
      if (ans % 2 != 0) {
        for (int i = 1; i < n; i += 2) {
          if (a[i] > a[i + 1]) {
            int temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp;
          }
        }
      } else {
        for (int i = 2; i <= n; i += 2) {
          if (a[i] > a[i + 1]) {
            int temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp;
          }
        }
      }
    }
    cout << ans << endl;
  }
}
