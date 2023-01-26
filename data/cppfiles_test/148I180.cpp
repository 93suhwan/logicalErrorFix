#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int w, h;
    cin >> w >> h;
    int ans = 0, max_diff = 0, max_diffy = 0;
    for (int i = 0; i < 2; i++) {
      int k;
      cin >> k;
      int a, b;
      cin >> a;
      k -= 2;
      while (k--) {
        int x;
        cin >> x;
      }
      cin >> b;
      max_diff = max(max_diff, b - a);
    }
    ans = h * max_diff;
    for (int i = 0; i < 2; i++) {
      int k;
      cin >> k;
      int a, b;
      cin >> a;
      k -= 2;
      while (k--) {
        int x;
        cin >> x;
      }
      cin >> b;
      max_diffy = max(max_diffy, b - a);
    }
    ans = max(ans, max_diffy * w);
    std::cout << ans << std::endl;
  }
  return 0;
}
