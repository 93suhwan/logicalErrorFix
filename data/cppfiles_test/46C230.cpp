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
    int cnt = 0;
    if (mx == a[n - 1]) {
      cout << 0 << endl;
    } else {
      int x = n - 1;
      while (a[x] != mx) {
        int curr = a[x];
        while (a[x] <= curr) x--;
        cnt++;
      }
      cout << cnt << endl;
    }
  }
}
