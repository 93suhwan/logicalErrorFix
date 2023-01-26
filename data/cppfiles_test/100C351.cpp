#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];
    sort(ar, ar + n);
    long long ans = ar[0];
    for (int i = 1; i < n; i++) {
      ans = max(ans, ar[i] - ar[i - 1]);
    }
    cout << ans << "\n";
  }
  return 0;
}
