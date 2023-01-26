#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int s = 0;
  int p = -1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x % 2) p = i;
    s += x;
  }
  for (int i = 2; i < s; i++) {
    if (s % i == 0) {
      s = 2;
      p = -1;
    }
  }
  if (s % 2)
    cout << n - 1;
  else
    cout << n;
  cout << '\n';
  for (int i = 0; i < n; i++) {
    if (i == p) continue;
    cout << i + 1 << " ";
  }
  cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
