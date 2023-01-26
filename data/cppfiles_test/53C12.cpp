#include <bits/stdc++.h>
using namespace std;
int n, k;
const int N = 1e5 + 10;
pair<int, int> a[N], b[N];
void solve() {
  cin >> n >> k;
  for (__typeof(n) i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a + 1, a + 1 + n);
  int ans = 1;
  for (__typeof(n - 1) i = 1; i <= n - 1; i++) {
    if (a[i].second + 1 != a[i + 1].second) ans++;
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
