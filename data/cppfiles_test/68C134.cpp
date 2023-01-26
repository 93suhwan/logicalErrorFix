#include <bits/stdc++.h>
using namespace std;
void solve() {
  int k;
  cin >> k;
  int n = sqrt(k);
  if (n * n == k) {
    cout << n << " 1"
         << "\n";
  } else {
    int diff = k - n * n;
    int s = diff - n - 1;
    if (diff <= n + 1) {
      cout << diff << " " << n + 1 << "\n";
    } else {
      cout << n + 1 << " " << n - s + 1 << "\n";
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
