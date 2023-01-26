#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, h;
    cin >> n >> h;
    long long int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    long long l = 1, r = h;
    while (l <= r) {
      long long m = (l + r) / 2;
      long long sum = m;
      for (int i = 0; i < n - 1; i++) {
        sum += min(a[i + 1] - a[i], m);
      }
      if (sum < h)
        l = m + 1;
      else {
        r = m - 1;
      }
    }
    cout << r + 1 << endl;
  }
}
