#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int N = 3e5 + 6;
int a[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    long long mx = -1;
    for (int i = 0; i < n - 1; ++i) mx = max(mx, 1ll * a[i] * a[i + 1]);
    cout << mx << endl;
  }
  return 0;
}
