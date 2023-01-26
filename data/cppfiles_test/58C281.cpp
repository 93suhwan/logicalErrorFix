#include <bits/stdc++.h>
using namespace std;
string x, y;
int t, n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> x >> y;
    int f = 1;
    for (int i = 0; i < n; i++) {
      if (x[i] == '1' && y[i] == '1') {
        f = 0;
        break;
      }
    }
    if (f)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
