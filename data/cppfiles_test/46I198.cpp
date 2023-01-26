#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t, nm, k, x;
  cin >> t;
  while (t--) {
    cin >> nm >> k;
    vector<long long> a, b;
    for (int i = 0; i < nm; i++) {
      cin >> x;
      if (x >= 0)
        a.push_back(x);
      else
        b.push_back(abs(x));
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int n = a.size();
    int m = b.size();
    long long res = 0;
    for (int i = n - 1; i >= 0; i -= k) {
      res += a[i] * 2;
    }
    for (int i = m - 1; i >= 0; i -= k) {
      res += b[i] * 2;
    }
    if (m == 0)
      res -= a[n - 1];
    else if (n == 0)
      res -= b[m - 1];
    else
      res -= max(a[n - 1], b[m - 1]);
    cout << res << "\n";
  }
  return 0;
}
