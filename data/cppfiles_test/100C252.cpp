#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, ans = 0, m = INT_MIN;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
      long long x = a[i] - ans;
      ans += x;
      m = max(x, m);
    }
    cout << m << endl;
  }
  return 0;
}
