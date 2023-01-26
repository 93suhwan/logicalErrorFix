#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, mx = -1;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  cout << (a[0] & a[n - 1]) << endl;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    solve();
  }
  return 0;
}
