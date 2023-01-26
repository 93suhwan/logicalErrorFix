#include <bits/stdc++.h>
using namespace std;
int n, k;
const int N = 1e5 + 10;
int a[N], b[N];
void solve() {
  cin >> n >> k;
  for (__typeof(n) i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
  int ans = 0;
  sort(b + 1, b + 1 + n);
  for (__typeof(n) i = 1; i <= n; i++) {
    int j = lower_bound(b + 1, b + 1 + n, a[i]) - b;
    if (a[i + 1] != b[j + 1]) ans++;
  }
  if (ans <= k)
    cout << "Yes\n";
  else
    cout << "No\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  int t;
  cin >> t;
  for (__typeof(t) i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
