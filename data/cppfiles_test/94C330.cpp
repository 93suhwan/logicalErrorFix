#include <bits/stdc++.h>
using namespace std;
int main() {
  (ios::sync_with_stdio(0), cin.tie(0));
  ;
  int t;
  cin >> t;
  while (t--) {
    long long n, k, ans = 0;
    cin >> n >> k;
    k++;
    vector<int> v(n);
    for (long long i = 0; i < n; i++) cin >> v[i];
    long long x, y;
    for (long long i = 0; i < n - 1; i++) {
      if (k > 0) {
        int f = v[i + 1] - v[i];
        x = pow(10, f);
        y = min(k, x - 1);
        ans += y * pow(10, v[i]);
        k = k - y;
      }
    }
    ans += k * pow(10, v.back());
    cout << ans;
    cout << "\n";
  }
  return 0;
}
