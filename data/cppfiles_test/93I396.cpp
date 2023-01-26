#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  int j;
  cin >> j;
  for (int i = 0; i < j; i++) {
    int n, k, tek = 1, hours = 0;
    cin >> n >> k;
    if (n == 1) {
      cout << 0 << "\n";
      continue;
    }
    for (int i = 1; tek < k; i++) {
      tek += tek;
      hours++;
      if (tek >= n) {
        cout << hours << "\n";
        break;
      }
    }
    if (tek < n) {
      int ans = hours;
      int l = (n - tek) / k;
      if (l * k == n - tek)
        cout << ans + l << "\n";
      else
        cout << ans + l + 1 << "\n";
    }
  }
  return 0;
}
