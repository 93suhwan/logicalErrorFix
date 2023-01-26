#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string alp;
    cin >> alp;
    int l = 0, r = 0;
    for (int i = 0; i < n - 1; i++) {
      if (alp[i] == 'a' && alp[i + 1] == 'b') {
        l = i + 1;
        r = i + 2;
        break;
      }
      if (alp[i] == 'b' && alp[i + 1] == 'a') {
        l = i + 1;
        r = i + 2;
        break;
      }
    }
    if (l != 0 && r != 0)
      cout << l << ' ' << r << endl;
    else
      cout << -1 << ' ' << -1 << endl;
  }
  return 0;
}
