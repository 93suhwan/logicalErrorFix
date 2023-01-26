#include <bits/stdc++.h>
using namespace std;
int a[300005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m, mx = 0;
    cin >> n >> m;
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++) {
      cin >> a[i];
    }
    mx = max(mx, (a[k] - a[1]) * m);
    cin >> k;
    for (int i = 1; i <= k; i++) {
      cin >> a[i];
    }
    mx = max(mx, (a[k] - a[1]) * m);
    cin >> k;
    for (int i = 1; i <= k; i++) {
      cin >> a[i];
    }
    mx = max(mx, (a[k] - a[1]) * n);
    cin >> k;
    for (int i = 1; i <= k; i++) {
      cin >> a[i];
    }
    mx = max(mx, (a[k] - a[1]) * n);
    cout << mx << endl;
  }
  return 0;
}
