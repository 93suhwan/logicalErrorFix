#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      if (i - 1 == 0) {
        cout << 1 << " ";
      } else {
        if ((i - 1) % 2) {
          cout << i << " ";
        }
      }
    }
    cout << endl;
  }
  return 0;
}
