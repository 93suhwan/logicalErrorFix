#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    long long n, k;
    cin >> n >> k;
    long long ar[n];
    int d = 0;
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      ar[i] = x;
    }
    long long mx = -1e18;
    for (long long i = n - 1; i >= max(0LL, n - 100); i--) {
      for (long long j = 0; j < n; j++) {
        if (i != j) {
          long long ans = ((i + 1) * (j + 1)) - (k * (ar[i] | ar[j]));
          mx = max(mx, ans);
        }
      }
    }
    cout << mx << endl;
  }
}
