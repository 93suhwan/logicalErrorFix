#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, e, f, g, i, j, l, r, k;
  cin >> a;
  while (a--) {
    cin >> b;
    long long arr[b + 3][6];
    for (i = 1; i <= b; i++) {
      for (j = 1; j <= 5; j++) {
        cin >> arr[i][j];
      }
    }
    bool chk = true;
    long long ans = 1;
    for (i = 1; i <= b; i++) {
      long long cnt = 0;
      for (j = 1; j <= 5; j++) {
        if (arr[i][j] < arr[ans][j]) {
          cnt++;
        }
      }
      if (cnt >= 3) {
        ans = i;
      }
    }
    for (i = 1; i <= b; i++) {
      long long cnt = 0;
      for (j = 1; j <= 5; j++) {
        if (arr[i][j] < arr[ans][j]) {
          cnt++;
        }
      }
      if (cnt >= 3) ans = -1;
    }
    cout << ans << endl;
  }
}
