#include <bits/stdc++.h>
using namespace std;
set<pair<int, int>> st;
int visited[1000000];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int a[k + 1][3];
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < 3; j++) {
        cin >> a[i][j];
        if (j == 1) visited[a[i][j]] = 1;
      }
    }
    int kk;
    for (int i = 1; i <= n; i++) {
      if (visited[i] == 0) {
        kk = i;
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i != kk) cout << kk << " " << i << endl;
    }
  }
  return 0;
}
