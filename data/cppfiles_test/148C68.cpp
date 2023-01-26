#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int w, h;
    cin >> w >> h;
    long long int a[4][2];
    for (long long int i = 0; i < 4; i++) {
      long long int k;
      cin >> k;
      a[i][0] = 1e7;
      a[i][1] = 0;
      for (long long int j = 0; j < k; j++) {
        long long int x;
        cin >> x;
        a[i][0] = min(a[i][0], x);
        a[i][1] = max(a[i][1], x);
      }
    }
    long long int ans = 0;
    long long int val0 = (a[0][1] - a[0][0]) * max({a[2][1], h, a[3][1]});
    long long int val1 = (a[1][1] - a[1][0]) * max(h, min(a[2][0], a[3][0]));
    long long int val3 = (a[2][1] - a[2][0]) * max({a[0][1], w, a[1][1]});
    long long int val4 = (a[3][1] - a[3][0]) * max(w, min(a[0][0], a[2][0]));
    cout << max({val0, val1, val3, val4}) << "\n";
    ;
  }
  return 0;
}
