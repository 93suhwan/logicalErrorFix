#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-O3")
#pragma GCC target("avx2")
using namespace std;
void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a - 1 + b - 1 + c - 1 < d) {
    cout << "NO\n";
    return;
  }
  int arr[3];
  arr[0] = a;
  arr[1] = b;
  arr[2] = c;
  sort(arr, arr + 3);
  if (arr[2] - arr[1] - arr[0] - 1 > d) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
