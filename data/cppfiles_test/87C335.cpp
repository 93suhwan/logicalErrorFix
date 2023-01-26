#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int m, n;
    cin >> m >> n;
    long long a[n], b[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b, b + n);
    long long ans = 0;
    long long c[n];
    for (int i = 0; i < n; i++) c[i] = 0;
    set<long long> vis;
    for (int i = 0; i < n; i++) {
      int k;
      for (int j = (n - 1); j >= 0; j--) {
        if (a[i] == b[j]) {
          if (vis.find(j) != vis.end()) continue;
          c[j] = a[i];
          k = j;
          vis.insert(j);
          break;
        }
      }
      for (int j = 0; j < k; j++) {
        if (c[j] != 0) ans++;
      }
    }
    cout << ans << "\n";
  }
}
