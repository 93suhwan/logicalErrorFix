#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    vector<int> a(n);
    for (int i = 0; i < (n); i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < (n - 2 * k); i++) ans += a[i];
    for (int i = n - 2 * k; i < n - k; i++) ans += a[i] / a[i + k];
    cout << ans << endl;
  }
}
