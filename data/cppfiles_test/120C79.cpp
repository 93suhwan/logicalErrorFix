#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const long long lnf = 0x3f3f3f3f3f3f3f3f;
int arr[200001][20];
int main(void) {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  for (int i = 1; i <= 200000; i++) {
    for (int j = 0; j < 20; j++) {
      if (!(i & (1 << j))) {
        arr[i][j] = arr[i - 1][j] + 1;
      } else {
        arr[i][j] = arr[i - 1][j];
      }
    }
  }
  while (t--) {
    int l, r;
    cin >> l >> r;
    int ans = inf;
    for (int j = 0; j < 20; j++) {
      ans = min(ans, arr[r][j] - arr[l - 1][j]);
    }
    cout << ans << "\n";
  }
  return 0;
}
