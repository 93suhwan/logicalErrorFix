#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, y;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    long long res, mx = 0;
    for (int i = 0; i < n - 1; i++) {
      res = a[i] * a[i + 1];
      mx = max(res, mx);
    }
    cout << mx << endl;
  }
}
