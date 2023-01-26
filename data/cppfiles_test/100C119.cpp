#include <bits/stdc++.h>
using namespace std;
int t, n;
const int maxn = 2e5 + 5;
int a[maxn];
int max1;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << a[1] << endl;
    return;
  }
  sort(a + 1, a + n + 1);
  max1 = a[1];
  for (int i = 2; i <= n; i++) {
    max1 = max(max1, a[i] - a[i - 1]);
  }
  cout << max1 << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
