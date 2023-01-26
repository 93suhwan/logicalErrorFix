#include <bits/stdc++.h>
using namespace std;
const int N = 109;
int T, n;
int a[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 1e9 + 7;
    for (int i = 0; i <= 50; i++)
      for (int j = 0; j <= 100; j++) {
        int flag = 0, temp = 0;
        for (int k = 1; k <= n && !flag; k++) {
          int z = a[k] - i - 2 * j;
          if (z < 0) {
            if (!i && z % 2) flag = 1;
          } else if (z % 3 == 1) {
            if (i < 2 && j < 1)
              flag = 1;
            else
              z += 2;
          } else if (z % 3 == 2) {
            if (i >= 1)
              z++;
            else if (j >= 2)
              z += 4;
            else
              flag = 1;
          }
          temp = max(temp, z / 3);
        }
        if (!flag) ans = min(ans, temp + i + j);
      }
    cout << ans << "\n";
  }
  return 0;
}
