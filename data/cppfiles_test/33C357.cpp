#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    long long ans = 1;
    for (int i = 1; i < n; i++) ans = max(ans, a[i] * a[i - 1]);
    cout << ans << "\n";
  }
  return 0;
}
