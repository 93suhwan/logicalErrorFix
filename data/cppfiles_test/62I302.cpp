#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int a[N];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (a[n] == 1) {
    cout << -1 << endl;
    return;
  }
  for (int i = 1; i <= n + 1; i++) cout << i << " ";
  cout << endl;
}
int main(void) {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
