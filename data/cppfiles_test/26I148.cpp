#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int long long m = 1e9 + 7;
    int long long ans = 1;
    if (n == 1) {
      cout << "1" << endl;
    } else {
      for (int i = 3; i <= 2 * n; i++) {
        ans = (ans * i) % m;
      }
    }
    cout << ans << endl;
  }
}
