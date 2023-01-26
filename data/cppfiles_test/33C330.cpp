#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    long long a[n], mx = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (long long i = 0; i < n - 1; i++) {
      mx = max(mx, a[i] * a[i + 1]);
    }
    cout << mx << "\n";
  }
}
