#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
const int mod = 1e9 + 7;
const long long inf = 1e18;
const char nl = '\n';
void CP() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); }
void solve() {
  int n;
  cin >> n;
  vector<bool> vis(1e6 + 1, true);
  vector<int> arr(n);
  for (auto& x : arr) {
    cin >> x;
    vis[x] = false;
  }
  sort(arr.begin(), arr.end());
  int cnt = 0, t = n / 2;
  for (int x = 0; x < (n); ++x) {
    for (int y = x + 1; y < (n); ++y) {
      if (vis[arr[y] % arr[x]] and arr[x] ^ arr[y]) {
        cout << arr[y] << " " << arr[x] << nl;
        cnt++;
      }
      if (cnt >= t) return;
    }
  }
}
int main() {
  CP();
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
