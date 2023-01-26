#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int w, h;
    cin >> w >> h;
    long long int ans = 0;
    for (int i = 1; i <= 4; i++) {
      long long int k;
      cin >> k;
      long long int a[k + 9];
      for (int j = 1; j <= k; j++) {
        cin >> a[j];
      }
      if (i < 3)
        ans = max((a[k] - a[1]) * h, ans);
      else
        ans = max((a[k] - a[1]) * w, ans);
    }
    cout << ans << "\n";
  }
  return 0;
}
