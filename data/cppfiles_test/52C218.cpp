#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    double x = 0, y = 0, z = n - 1;
    for (int i = 0; i < n - 1; i++) {
      x += a[i];
    }
    for (int i = 1; i < n; i++) {
      y += a[i];
    }
    x /= z;
    x += (double)a[n - 1];
    y /= z;
    y += (double)a[0];
    cout << fixed << setprecision(10) << max(x, y) << '\n';
  }
  return 0;
}
