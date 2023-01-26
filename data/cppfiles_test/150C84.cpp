#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(15);
  cout << fixed;
  long long t, n, m, i, j, k, l, sz;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < (int)(n); ++i) cin >> v[i];
    long long xx = 0, ans = INT_MAX, mx = 0;
    for (int i = 0; i < (int)(n); ++i) {
      if (v[i] % 3 != 0)
        mx = INT_MAX;
      else
        mx = max(mx, v[i] / 3);
    }
    ans = min(ans, mx);
    mx = 0;
    for (int i = 0; i < (int)(n); ++i) {
      if (v[i] % 3 == 1)
        mx = INT_MAX;
      else
        mx = max(mx, v[i] / 3);
    }
    ans = min(ans, mx + 1);
    mx = 0;
    for (int i = 0; i < (int)(n); ++i) {
      if (v[i] % 3 == 2)
        mx = INT_MAX;
      else
        mx = max(mx, v[i] / 3);
    }
    ans = min(ans, mx + 1);
    mx = 0;
    for (int i = 0; i < (int)(n); ++i) {
      if (v[i] % 3 == 0)
        mx = max(mx, v[i] / 3 - 1);
      else
        mx = max(mx, v[i] / 3);
    }
    ans = min(ans, mx + 2);
    mx = 0;
    for (int i = 0; i < (int)(n); ++i) {
      if (v[i] == 1)
        mx = INT_MAX;
      else if (v[i] % 3 == 1)
        mx = max(mx, (v[i] - 4) / 3);
      else
        mx = max(mx, v[i] / 3);
    }
    ans = min(ans, mx + 2);
    cout << ans << "\n";
  }
}
