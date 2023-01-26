#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    long long mx = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
      ans = max(ans, (a[i] * a[i + 1]));
    }
    cout << ans << "\n";
  }
  return 0;
}
