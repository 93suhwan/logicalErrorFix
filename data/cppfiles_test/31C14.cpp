#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 9;
int a[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n % 2 == 0) {
      for (int i = n; i >= n / 2 + 1; i--) cout << -a[i] << " ";
      for (int i = n / 2; i >= 1; i--) cout << a[i] << " ";
      cout << endl;
    } else {
      int pos1, pos2, pos3;
      int f = 0;
      for (int i = 1; i <= 2; i++) {
        if (f == 1) break;
        for (int j = i + 1; j <= 3; j++) {
          if (a[i] + a[j] != 0) {
            pos1 = i, pos2 = j;
            f = 1;
            break;
          }
        }
      }
      for (int i = 1; i <= 3; i++) {
        if (i != pos1 && i != pos2) {
          pos3 = i;
          break;
        }
      }
      for (int i = 1; i <= 3; i++) {
        if (i == pos1 || i == pos2)
          cout << a[pos3] << " ";
        else
          cout << -(a[pos1] + a[pos2]) << " ";
      }
      if (n > 3) {
        int x = n - 3;
        for (int i = n; i >= x / 2 + 1 + 3; i--) cout << -a[i] << " ";
        for (int i = x / 2 + 3; i >= 4; i--) cout << a[i] << " ";
        cout << endl;
      }
    }
  }
  return 0;
}
