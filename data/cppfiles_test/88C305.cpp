#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, n, m, x;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    long long a[n * m], b[n * m];
    for (int i = 0; i < n * m; i++) {
      cin >> x;
      a[i] = x;
      b[i] = x;
    }
    sort(b, b + n * m);
    int adj[n][m];
    int i = n * m - 1;
    for (int j = n - 1; j >= 0; j--) {
      for (int k = m - 1; k >= 0; k--) {
        adj[j][k] = b[i--];
      }
    }
    long long ans = 0;
    for (i = 0; i < n * m; i++) {
      int j = 0;
      for (j = 0; j < n; j++) {
        int x1 = adj[j][0];
        int x2 = adj[j][m - 1];
        if (x2 < 0) x2 = -x2;
        if (x1 < 0) x1 = -x1;
        if (a[i] <= x2 && a[i] >= x1) break;
      }
      int check = false;
      while (!check) {
        int k = m - 1;
        for (; k >= 0; k--)
          if (adj[j][k] == a[i]) {
            check = true;
            break;
          }
        if (check) {
          adj[j][k] = -a[i];
          for (int l = 0; l < k; l++)
            if (adj[j][l] < 0) ans++;
          break;
        }
        j++;
      }
    }
    cout << ans << endl;
  }
  return (0);
}
