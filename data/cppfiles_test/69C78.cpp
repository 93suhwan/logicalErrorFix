#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    unsigned long long int arr[100];
    int d = 0;
    for (int i = 0; i < 64; i++) arr[i] = pow(2, i);
    int t = n;
    int brr[100];
    while (t != 0) {
      brr[d++] = t % 10;
      t /= 10;
    }
    reverse(brr, brr + d);
    int ans = 10;
    for (int i = 0; i < 64; i++) {
      int crr[100], q = 0;
      unsigned long long int r = arr[i];
      while (r != 0) {
        crr[q++] = r % 10;
        r /= 10;
      }
      reverse(crr, crr + q);
      int h = 0, w = 0;
      int cnt = 0;
      for (int j = 0; j < q; j++) {
        for (int k = h; k < d; k++) {
          if (crr[j] == brr[k]) {
            w++;
            h++;
            break;
          } else {
            h++;
            cnt++;
          }
        }
        if (w == q) {
          ans = min(ans, cnt + d - h);
          break;
        }
      }
      if (w != q) ans = min(ans, cnt + q - w);
    }
    cout << ans << endl;
  }
  return 0;
}
