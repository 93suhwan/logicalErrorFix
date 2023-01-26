#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n][2];
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
    for (int i = 0; i < n; i++) {
      int l = a[i][0], r = a[i][1];
      cout << l << " " << r << " ";
      if (l == r) {
        cout << l << endl;
        continue;
      }
      int d = l - 1;
      for (int j = 0; j < n; j++) {
        if (i != j && a[j][0] == l && a[j][1] <= r) {
          d = max(d, a[j][1]);
        }
      }
      cout << d + 1 << endl;
    }
    cout << endl;
  }
  return 0;
}
