#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[3][N];
int s1[N];
int s2[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= 2; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
      }
    }
    for (int i = 1; i <= n; i++) {
      s1[i] = s1[i - 1] + a[1][i];
      s2[i] = s2[i - 1] + a[2][i];
    }
    int res = 0;
    int maxx = -1;
    int ans = 0x3f3f3f3f;
    int k;
    for (int i = 1; i <= n; i++) {
      if (i == 1) {
        k = s1[n] - s1[1];
      } else if (i == n) {
        k = s2[n - 1];
      } else {
        k = max(s1[n] - s1[i], s2[i - 1]);
      }
      ans = min(ans, k);
    }
    cout << ans << endl;
  }
  return 0;
}
