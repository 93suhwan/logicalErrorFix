#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, i, j;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < n; i++) {
      if (a[i] % (i + 2) == 0) {
        for (j = 2; j < i + 2; j++) {
          if (a[i] % (j) != 0) break;
        }
        if (j == i + 2) break;
      }
    }
    if (i == n)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
