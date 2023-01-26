#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;
int a[MAX];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int c = 0;
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    if (a[i] != i) {
      if ((a[i] - 1) / 2 >= i) {
        c++;
      } else {
        cout << -1 << "\n";
        return;
      }
    }
  }
  cout << c << "\n";
  return;
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
