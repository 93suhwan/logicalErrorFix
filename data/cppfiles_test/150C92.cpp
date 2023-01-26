#include <bits/stdc++.h>
using namespace std;
long long inf = 1e18;
int __FAST_IO__ = []() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  return 0;
}();
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < (N); ++i) cin >> v[i];
    int ans = 1e9;
    for (int i = 0; i < (5); ++i)
      for (int j = 0; j < (5); ++j) {
        int tot = i + j * 2;
        vector<int> mo(tot + 1, -1);
        for (int x = 0; x < (i + 1); ++x)
          for (int y = 0; y < (j + 1); ++y) {
            mo[x + y * 2] = x + y;
          }
        int ans2 = 0;
        for (int k = 0; k < (N); ++k) {
          bool flag = false;
          for (int x = (tot); x >= 0; --x) {
            if (mo[x] >= 0 && v[k] >= x && (v[k] - x) % 3 == 0) {
              ans2 = max(ans2, (v[k] - x) / 3);
              flag = true;
              break;
            }
          }
          if (!flag) {
            ans2 = 1e9;
            break;
          }
        }
        ans = min(ans, ans2 + i + j);
      }
    printf("%d\n", ans);
  }
  return 0;
}
