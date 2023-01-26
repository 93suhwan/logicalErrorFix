#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, i, ans, max = 0;
    cin >> n;
    long long int a[n];
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < n - 1; i++) {
      ans = a[i] * a[i + 1];
      if (ans > max) max = ans;
    }
    cout << max << "\n";
  }
}
