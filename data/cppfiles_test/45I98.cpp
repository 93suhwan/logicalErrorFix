#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    long long int odd = 0, even = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] & 1)
        odd++;
      else
        even++;
    }
    if (abs(odd - even) > 1)
      cout << -1 << endl;
    else {
      long long int ans = 0;
      if (a[0] % 2 == 0) {
        long long int st = 1;
        for (long long int i = 0; i < n; i++) {
          if (a[i] & 1) {
            ans += (abs(st - i));
            st += 2;
          }
        }
        cout << ans << endl;
      } else {
        long long int st = 0;
        for (long long int i = 0; i < n; i++) {
          if (a[i] & 1) {
            ans += (abs(st - i));
            st += 2;
          }
        }
        cout << ans << endl;
      }
    }
  }
  return 0;
}
