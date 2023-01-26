#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout.precision(15);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    long long ans = a[0];
    for (int i = 0; i < n - 1; i++) {
      ans = max(ans, a[i + 1] - a[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
