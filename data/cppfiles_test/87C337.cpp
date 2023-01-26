#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n + 1];
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long int ans = 0;
    for (int i = 1; i <= n; i++) {
      long long int t1 = a[i] - (i + ans);
      if (t1 > 0) {
        ans += t1;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
