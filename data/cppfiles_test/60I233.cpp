#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n + 2];
    int mx = -1;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] > mx) mx = a[i];
    }
    int ans = mx;
    for (int i = 0; i < n; i++) {
      int op = mx & a[i];
      if (op < ans) ans = op;
    }
    cout << ans << endl;
  }
}
