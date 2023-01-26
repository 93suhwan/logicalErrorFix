#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int ans = 1;
    vector<long long int> days(n);
    for (long long int i = 0; i < n; i++) cin >> days[i];
    ans += days[0];
    for (long long int i = 1; i < n; i++) {
      if (days[i - 1] == 0 && days[i] == 0) {
        ans = -1;
        break;
      } else if (days[i - 1] == 1 && days[i] == 1)
        ans += 5;
      else if (days[i] == 1)
        ans++;
    }
    cout << ans << "\n";
  }
}
