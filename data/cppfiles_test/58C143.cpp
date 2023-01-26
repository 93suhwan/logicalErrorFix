#include <bits/stdc++.h>
using namespace std;
int t, n, i;
string m[2];
bool b;
int main() {
  cin >> t;
  while (t > 0) {
    t--;
    cin >> n >> m[0] >> m[1];
    b = 1;
    for (i = 0; i < n; i++) {
      if (m[0][i] == '1' && m[1][i] == '1') {
        b = 0;
        break;
      }
    }
    if (b == 0) {
      cout << "NO";
    } else {
      cout << "YES";
    }
    cout << endl;
  }
  return 0;
}
