#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    int n, m, i, j, ti, tj;
    cin >> n >> m >> i >> j >> ti >> tj;
    int di = 1, dj = 1;
    int ans = 0;
    while (i != ti && j != tj) {
      if (i + di > n) di = -1;
      if (j + dj > m) dj = -1;
      i += di, j += dj;
      ans++;
    }
    cout << ans << endl;
  }
}
