#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    long long ans = -100000000000;
    cin >> n >> k;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int l = max(1, n - 2 * k);
    for (int i = l; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        ans = max(ans, i * j - k * (a[i] | a[j]));
      }
    }
    cout << ans << '\n';
  }
}
