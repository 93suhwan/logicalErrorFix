#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int main() {
  int a[N];
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int mmax = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] > mmax) mmax = a[i];
    }
    int mmin = a[n - 1];
    int ans = 0;
    int p = n - 1;
    while (mmin != mmax) {
      while (a[p] <= mmin && p > 0) {
        p--;
      }
      mmin = a[p];
      ++ans;
    }
    cout << ans << endl;
  }
}
