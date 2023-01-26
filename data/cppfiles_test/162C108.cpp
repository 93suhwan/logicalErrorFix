#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const int MAX = 2e5 + 10;
const long long MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;
const long double PI = acos(-1);
bool check(int m, vector<long long> &h, int n) {
  vector<long long> hi(n, 0);
  for (int i = n - 1; i >= 2; i--) {
    if (h[i] + hi[i] < m) return false;
    long long d = min(h[i] / 3, (h[i] + hi[i] - m) / 3);
    hi[i - 1] += d;
    hi[i - 2] += 2 * d;
  }
  if (h[0] + hi[0] < m or h[1] + hi[1] < m) return false;
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    long long l = 0, r = 1e9 + 10, ans = 0;
    while (l <= r) {
      long long m = (l + r) / 2;
      if (check(m, h, n)) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
