#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = -1;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mx = max(mx, a[i]);
    }
    if (mx == a[n - 1]) {
      cout << 0 << endl;
    } else {
      int cnt = 1;
      for (int i = n - 2; i >= 0; i--) {
        if (a[i] < mx && a[i] > a[n - 1]) {
          cnt++;
        }
      }
      cout << cnt / 2 << endl;
    }
  }
}
