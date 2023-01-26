#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    long long h;
    cin >> n >> h;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long l = 1, r = 1e18;
    while (l <= r) {
      long long m = (l + r) / 2;
      long long sum = m;
      for (int i = 1; i < n; i++) {
        sum += min(m, a[i + 1] - a[i]);
      }
      if (sum < h)
        l = m + 1;
      else
        r = m - 1;
    }
    cout << r + 1 << endl;
  }
}
