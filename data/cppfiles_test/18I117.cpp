#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    int n, d, f = 0;
    cin >> n >> d;
    vector<int> a(n), temp(n), ans(2 * n);
    for (auto &i : a) cin >> i;
    for (int i = 0; i < n; i++) {
      temp[i] = a[(i - d + n) % n];
      if (a[i]) f = 1;
      ans[i] = a[i];
    }
    if (temp == a && f) {
      cout << "-1\n";
      continue;
    }
    if (!f) {
      cout << "0\n";
      continue;
    }
    if (d != n) {
      int k = 0;
      for (int i = 0; i < n; i++) {
        ans[i] = a[k] & a[(k - d + n) % n];
        ans[n + i] = ans[i];
        k = (k - d + n) % n;
      }
    }
    int len = 0;
    int mxm = 0;
    for (int i = 0; i < 2 * n; i++) {
      if (ans[i])
        len++;
      else {
        mxm = max(mxm, len);
        len = 0;
      }
    }
    mxm = max(mxm, len);
    cout << mxm + 1 << "\n";
  }
}
