#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int ar[N];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int flag = 0;
    int n;
    cin >> n;
    if (n % 2 == 0) flag = 1;
    for (int i = 1; i <= n; i++) cin >> ar[i];
    if (!flag) {
      for (int i = 2; i <= n; i++) {
        if (ar[i] <= ar[i - 1]) {
          flag = 1;
          break;
        }
      }
      if (flag)
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    } else
      cout << "YES" << '\n';
  }
}
