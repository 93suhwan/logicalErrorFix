#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005], c[100005];
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    a[i] = b[i];
  }
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++) c[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
  int tot = 1;
  for (int i = 1; i < n; i++) {
    if (c[i + 1] - c[i] != 1) tot++;
  }
  cout << (tot > k ? "No" : "Yes") << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
