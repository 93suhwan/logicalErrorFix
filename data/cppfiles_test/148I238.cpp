#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    int w, h, k, z;
    cin >> w >> h;
    int ans = 0, a, b;
    cin >> k;
    for (int i = 0; i < k; i++) {
      cin >> z;
      if (i == 0) {
        a = z;
      } else if (i == k - 1) {
        b = z;
      }
    }
    ans = max(ans, h * (b - a));
    cin >> k;
    for (int i = 0; i < k; i++) {
      cin >> z;
      if (i == 0) {
        a = z;
      } else if (i == k - 1) {
        b = z;
      }
    }
    ans = max(ans, h * (b - a));
    cin >> k;
    for (int i = 0; i < k; i++) {
      cin >> z;
      if (i == 0) {
        a = z;
      } else if (i == k - 1) {
        b = z;
      }
    }
    ans = max(ans, w * (b - a));
    cin >> k;
    for (int i = 0; i < k; i++) {
      cin >> z;
      if (i == 0) {
        a = z;
      } else if (i == k - 1) {
        b = z;
      }
    }
    ans = max(ans, w * (b - a));
    cout << ans << "\n";
  }
  return 0;
}
