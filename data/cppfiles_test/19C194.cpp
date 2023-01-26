#include <bits/stdc++.h>
using namespace std;
long long all, ans, i, j, base;
int n;
bool flag;
int a[100];
void solve() {
  base = 1;
  for (i = 1; i <= n; i++) base *= 3;
  base--;
  while (base) {
    ans = 0, j = 0;
    for (i = base; i != 0; i /= 3) {
      if (i % 3 == 2) ans += a[j];
      if (i % 3 == 1) ans -= a[j];
      j++;
    }
    if (!ans) {
      cout << "YES\n";
      return;
    }
    base--;
  }
  cout << "NO\n";
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    all = 1;
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
    solve();
  }
}
