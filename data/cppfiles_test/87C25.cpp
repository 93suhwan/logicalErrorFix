#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(a[i] - i - 1, ans);
  }
  cout << ans << endl;
}
int main() {
  int g;
  cin >> g;
  while (g--) {
    solve();
  }
  return 0;
}
