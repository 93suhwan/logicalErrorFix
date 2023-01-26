#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    cout << s / (n - (n - 1) / 2) << "\n";
  }
  return 0;
}
