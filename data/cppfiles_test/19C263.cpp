#include <bits/stdc++.h>
using namespace std;
int ar[201];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  for (int i = 0; i < n; i++) {
    if (ar[i] == 0) {
      cout << "YES\n";
      return;
    }
    int mask = (1 << n) - 1;
    mask = (mask ^ (1 << i));
    int s = mask;
    while (s > 0) {
      int q = s;
      while (q >= 0) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
          if (s & (1 << j)) {
            if (q & (1 << j)) {
              sum += ar[j];
            } else {
              sum -= ar[j];
            }
          }
        }
        if (sum == ar[i]) {
          cout << "YES\n";
          return;
        }
        if (q == 0) break;
        q = (q - 1) & s;
      }
      s = (s - 1) & mask;
    }
  }
  cout << "NO\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  int test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
