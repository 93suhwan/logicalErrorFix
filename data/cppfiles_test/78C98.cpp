#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int bit[32] = {0};
  for (int b = 0; b < 32; b++) {
    for (int i = 0; i < n; i++) {
      bool f = (a[i] & (1 << b));
      if (f) {
        bit[b]++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    bool f = true;
    for (int b = 0; b < 32; b++) {
      if (bit[b] % i != 0) {
        f = false;
        break;
      }
    }
    if (f) {
      cout << i << ' ';
    }
  }
  cout << '\n';
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
