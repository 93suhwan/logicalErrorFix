#include <bits/stdc++.h>
constexpr int maxT = 5e3;
int t;
int b[7];
int b2[7];
bool x;
int ans[3];
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::cin >> t;
  while (t--) {
    for (int i = 0; i < 7; i++) {
      std::cin >> b[i];
    }
    x = false;
    for (int i = 0; !x && i < 7; i++) {
      for (int j = i + 1; !x && j < 7; j++) {
        for (int ii = j + 1; !x && ii < 7; ii++) {
          b2[0] = b[i];
          b2[1] = b[j];
          b2[2] = b[ii];
          b2[3] = b2[0] + b2[1];
          b2[4] = b2[0] + b2[2];
          b2[5] = b2[1] + b2[2];
          b2[6] = b2[0] + b2[1] + b2[2];
          ans[0] = b2[0];
          ans[1] = b2[1];
          ans[2] = b2[2];
          std::sort(b2, b2 + 7);
          x = true;
          for (int jj = 0; jj < 7; jj++) {
            if (b2[jj] != b[jj]) {
              x = false;
              break;
            }
          }
        }
      }
    }
    std::cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << "\n";
  }
}
