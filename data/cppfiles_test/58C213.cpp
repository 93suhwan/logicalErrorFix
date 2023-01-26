#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a;
    cin >> a;
    string b;
    cin >> b;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (a[i] == '1' && b[i] == '1') {
        ok = false;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
  return 0;
}
