#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = a[0];
    for (int i = 2; i < n; i++) ans = ans & a[i];
    cout << ans << endl;
  }
  return 0;
}
