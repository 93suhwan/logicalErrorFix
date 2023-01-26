#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, c1 = 1;
    cin >> n;
    string a;
    cin >> a;
    string b;
    cin >> b;
    for (int i = 0; i < n; i++) {
      if (a[i] == '1' && b[i] == '1') {
        c1 = 0;
        break;
      }
    }
    if (c1 == 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
