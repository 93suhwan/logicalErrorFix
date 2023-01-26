#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int ng = n / k;
  if (n % k) ng++;
  int ans = 2;
  if (ng >= 3 && k <= ng - 1) {
    ans = 3;
  }
  if (ng == 1) {
    ans = 1;
  }
  cout << ans << endl;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int g1 = i / k;
      int g2 = j / k;
      if (g1 == g2)
        cout << 1 << " ";
      else {
        if (ans == 2) {
          cout << 2 << " ";
        } else {
          if (g2 & 1) {
            cout << 2 << " ";
          } else {
            cout << 3 << " ";
          }
        }
      }
    }
  }
}
