#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10, mod = 7 + 1e9;
const double eps = 1e-7;
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int mul(int a, int b) { return (long long)a * b % mod; }
void Ihatemylife() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it : a) cin >> it;
    int mx = 1e9;
    for (int r = 0, l = 0; r < n; ++r) {
      vector<int> b(n);
      for (int i = 0; i <= r - l; ++i) {
        b[i] = a[l + i] & a[r - i];
      }
      int mxi = -1;
      for (int i = 0; i < n; ++i) {
        mxi = max(mxi, b[i]);
      }
      mx = min(mx, mxi);
    }
    cout << mx << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  Ihatemylife();
  return 0;
}
