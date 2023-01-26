#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int ans;
int x;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> ans;
    for (int i = 2; i <= n; i++) {
      cin >> x;
      ans = ans & x;
    }
    cout << ans << endl;
  }
  return 0;
}
