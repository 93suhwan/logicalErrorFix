#include <bits/stdc++.h>
using namespace std;
long long t, n, k, a[10];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long pow10[10];
  pow10[0] = 1;
  for (int i = 1; i < 10; i++) {
    pow10[i] = pow10[i - 1] * 10;
  }
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    k++;
    long long cur, ans = 0;
    for (int i = 0; i < n - 1 && k > 0; i++) {
      cur = min(pow10[a[i + 1] - a[i]] - 1, k);
      k -= cur;
      ans += pow10[a[i]] * cur;
    }
    ans += pow10[a[n - 1]] * k;
    cout << ans << endl;
  }
}
