#include <bits/stdc++.h>
using namespace std;
int n[5];
int maxx = -1;
int a[5][1000005];
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    maxx = -1;
    int w, h;
    cin >> w >> h;
    cin >> n[1];
    for (int i = 1; i <= n[1]; i++) cin >> a[1][i];
    cin >> n[2];
    for (int i = 1; i <= n[2]; i++) cin >> a[2][i];
    cin >> n[3];
    for (int i = 1; i <= n[3]; i++) cin >> a[3][i];
    cin >> n[4];
    for (int i = 1; i <= n[4]; i++) cin >> a[4][i];
    for (int i = 1; i <= 4; i++) {
      int p1 = a[i][1];
      int p2 = a[i][n[i]];
      int c = p2 - p1;
      if (i == 1 || i == 2)
        maxx = max(maxx, c * h);
      else
        maxx = max(maxx, c * w);
    }
    cout << maxx << endl;
  }
  return 0;
}
