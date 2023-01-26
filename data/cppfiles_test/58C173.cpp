#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> t;
  while (t--) {
    cin >> n;
    string r1, r2;
    cin >> r1 >> r2;
    int flag = 0;
    for (int i = 0; i < n; i++) {
      if (r1[i] == r2[i] && r1[i] == '1') {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
