#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int num;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
      cin >> num;
      if (num % 2 == 0) {
        c1++;
      } else {
        c2++;
      }
    }
    if (c1 == n || c2 == n) {
      cout << 0 << endl;
    } else {
      if (c1 == c2) {
        cout << 0 << endl;
      } else {
        cout << 1 << endl;
      }
    }
  }
  return 0;
}
