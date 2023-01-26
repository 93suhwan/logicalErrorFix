#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    b = a;
    sort(b.begin(), b.end());
    if (a == b)
      cout << 0 << endl;
    else {
      int ans = 0;
      int k = 0;
      while (true) {
        if (k == 1) {
          for (int i = 1; i < n - 1; i++) {
            if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
            i++;
          }
          k = 0;
        } else {
          for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
            i++;
          }
          k = 1;
        }
        ans++;
        if (a == b) break;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
