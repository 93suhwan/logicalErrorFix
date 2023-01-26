#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int n;
int fun(int x) {
  cout << "case " << x << endl;
  int ans = 0;
  int delta = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] != x) {
      delta += (x - arr[i]);
    }
    ans += abs(delta);
    x ^= 1;
  }
  return ans;
}
void solve() {
  cin >> n;
  int f[2];
  f[0] = 0;
  f[1] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    arr[i] = arr[i] % 2;
    f[arr[i]]++;
  }
  if (n % 2 == 0) {
    if (f[0] == f[1]) {
      int ans = min(fun(0), fun(1));
      cout << ans << endl;
    } else
      cout << -1 << endl;
  } else {
    if (f[0] == f[1] + 1)
      cout << fun(0) << endl;
    else if (f[1] == f[0] + 1)
      cout << fun(1) << endl;
    else
      cout << -1 << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
