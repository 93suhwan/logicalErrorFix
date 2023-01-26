#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    int r[n][5];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> r[i][j];
      }
    }
    int k = 0;
    for (int i = 1; i < n; i++) {
      int cnt = 0;
      for (int j = 0; j < 5; j++) {
        if (r[k][j] < r[i][j]) {
          cnt++;
        }
      }
      if (cnt < 3) {
        k = i;
      }
    }
    bool bl = 1;
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (int j = 0; j < 5; j++) {
        if (r[k][j] <= r[i][j]) {
          cnt++;
        }
      }
      if (cnt < 3) {
        bl = 0;
        break;
      }
    }
    if (bl) {
      cout << k + 1 << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
  return 0;
}
