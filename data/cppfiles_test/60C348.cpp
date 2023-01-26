#include <bits/stdc++.h>
using namespace std;
const char en = '\n';
void solve() {
  int n;
  scanf("%d", &n);
  int i;
  vector<int> a(n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int ans = a[0];
  for (i = 1; i < n; i++) {
    ans = ans & a[i];
  }
  cout << ans << en;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
