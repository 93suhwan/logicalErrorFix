#include <bits/stdc++.h>
using namespace std;
int n, m, conn[50][50];
int main() {
  cin >> n >> m;
  n = min(n, 50);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    if (max(u, v) < n) {
      conn[u][v] = conn[v][u] = 1;
    }
  }
  int arr[5];
  for (arr[0] = 0; arr[0] < n; arr[0]++) {
    for (arr[1] = arr[0] + 1; arr[1] < n; arr[1]++) {
      for (arr[2] = arr[1] + 1; arr[2] < n; arr[2]++) {
        for (arr[3] = arr[2] + 1; arr[3] < n; arr[3]++) {
          for (arr[4] = arr[3] + 1; arr[4] < n; arr[4]++) {
            int ct = 0;
            for (int i = 0; i < 5; i++) {
              for (int j = i + 1; j < 5; j++) {
                ct += conn[arr[i]][arr[j]];
              }
            }
            if (ct == 0 || ct == 10) {
              for (int i = 0; i < 5; i++) {
                cout << arr[i] + 1 << " ";
              }
              cout << endl;
              return 0;
            }
          }
        }
      }
    }
  }
  cout << -1 << endl;
}
