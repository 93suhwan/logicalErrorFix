#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    long long int mx = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      mx = max(a[i], mx);
    }
    long long int val = a[n - 1];
    long long int res = 0;
    if (mx == a[n - 1]) {
      cout << 0 << "\n";
      ;
      continue;
    }
    for (long long int i = n - 2; i >= 0; i--) {
      if (a[i] == mx) {
        res++;
        break;
      }
      if (a[i] > val) {
        res++;
        val = a[i];
      }
    }
    cout << res << "\n";
    ;
  }
  return 0;
}
