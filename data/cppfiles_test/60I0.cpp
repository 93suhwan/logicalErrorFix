#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int getPairsCount(long long int arr[], long long int n,
                            long long int k) {
  unordered_map<long long int, long long int> m;
  long long int count = 0;
  for (long long int i = 0; i < n; i++) {
    if (m.find(k - arr[i]) != m.end()) {
      count += m[k - arr[i]];
    }
    m[arr[i]]++;
  }
  return count;
}
void solve() {
  long long int n, i, j;
  cin >> n;
  long long int a[n], sum = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i], sum += a[i];
  }
  if ((2 * sum) % n == 0) {
    long long int me = sum / n;
    long long int ans = getPairsCount(a, n, me * 2);
    cout << ans << endl;
  } else {
    cout << 0 << endl;
  }
}
int main() {
  long long int t = 1, i, j;
  cin >> t;
  long long int lovely = 1;
  while (t--) {
    solve();
  }
  return 0;
}
