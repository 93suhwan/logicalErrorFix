#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    vector<long long> a(n), values(n);
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      values[i] = pow(10, a[i]);
    }
    vector<long long> canUse(n - 1);
    for (long long int i = 0; i < n - 1; i++) {
      canUse[i] = (values[i + 1] / values[i]) - 1LL;
    }
    long long int ans = 0;
    k++;
    for (long long int i = 0; i < n - 1; i++) {
      long long int useHere = min(canUse[i], k);
      k -= useHere;
      ans += (useHere * values[i]);
    }
    if (k > 0) {
      ans += (k * values[n - 1]);
    }
    cout << ans << "\n";
  }
  return 0;
}
