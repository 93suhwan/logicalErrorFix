#include <bits/stdc++.h>
using namespace std;
long long M = 1000000007;
long long bin(long long n, long long k) {
  long long res = 1;
  if (k > n - k) k = n - k;
  for (int i = 0; i < k; i++) {
    res *= (n - i);
    res /= (i + 1);
    res %= M;
  }
  return res;
}
void solve() {
  long long n, i, k, x, ct = 0, ans = 0;
  cin >> n;
  long long a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long mn = a[0];
  k = a[0];
  for (i = 1; i < n; i++) {
    mn = max(mn, a[i] - a[i - 1]);
  }
  cout << mn << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
