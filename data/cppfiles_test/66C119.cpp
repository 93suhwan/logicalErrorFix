#include <bits/stdc++.h>
using namespace std;
void solve() {
  int k;
  cin >> k;
  int a[10000];
  int j = 1;
  for (int i = 1; i <= 1666; i++) {
    if (i % 3 == 0 || i % 10 == 3) continue;
    a[j] = i;
    j++;
  }
  cout << a[k] << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
