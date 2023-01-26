#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int a[N];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (a[n] == 0 || a[1] == 1) {
    for (int i = 1; i <= n + 1; i++) cout << i << " ";
    cout << endl;
    return;
  }
  for (int i = 1; i <= n - 1; i++) {
    if (a[i] == 0 && a[i + 1] == 1) {
      for (int j = 1; j < i; j++) cout << j << " ";
      cout << i << " " << n + 1 << " ";
      for (int j = i + 1; j <= n; j++) cout << j << " ";
      cout << endl;
    }
  }
}
int main(void) {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
