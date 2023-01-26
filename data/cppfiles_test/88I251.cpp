#include <bits/stdc++.h>
using namespace std;
long long int powerMod(long long int x, unsigned long long int y) {
  if (y == 0) return 1;
  long long int p = powerMod(x, y / 2) % 1000000007;
  p = (p * p) % 1000000007;
  return (y % 2 == 0) ? p : (x * p) % 1000000007;
}
long long int power(long long int x, unsigned long long int y) {
  if (y == 0) return 1;
  long long int p = power(x, y / 2);
  p = (p * p);
  return (y % 2 == 0) ? p : (x * p);
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    if (n % 2 == 0)
      cout << "YES\n";
    else {
      long long int cnt = 0;
      for (int i = 0; i < n - 1; ++i) {
        if (arr[i + 1] > arr[i]) {
          ++cnt;
          ++i;
        }
      }
      if (cnt % 2 == 0) {
        cout << "YES\n";
      } else
        cout << "NO\n";
    }
  }
}
