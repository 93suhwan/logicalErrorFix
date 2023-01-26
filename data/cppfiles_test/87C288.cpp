#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n], best = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    best = max(best, a[i] - i - 1);
  }
  cout << best << "\n";
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
