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
    for (int i = 0; i < n; i++) cin >> a[i];
    int h = 1;
    for (int i = 0; i < n; i++) {
      if (a[i] == 1 && i == 0) {
        h += 1;
      }
      if (a[i] == 1 && i > 0) {
        if (a[i] == 1 && a[i - 1] == 1)
          h += 5;
        else
          h += 1;
      }
      if (a[i] == 0) h = h;
      if ((i + 1) < n) {
        if (a[i] == 0 && a[i + 1] == 0) {
          h = -1;
          break;
        }
      }
    }
    cout << h << "\n";
  }
  return 0;
}
