#include <bits/stdc++.h>
using namespace std;
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long sum = 0, i, m = LLONG_MIN;
    long long n;
    cin >> n;
    for (i = 0; i < n; i++) {
      long long x;
      cin >> x;
      sum += x;
      m = max(m, x);
    }
    sum -= m;
    double y = sum / (double)(n - 1);
    cout << fixed << setprecision(10);
    cout << m + y << endl;
  }
}
