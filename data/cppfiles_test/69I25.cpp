#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ctr1 = 0, ctr2 = 0;
    for (int i = 1; i <= n; i++) {
      int b;
      cin >> b;
      if (b == 1) ctr1++;
      if (b == 2) ctr2++;
    }
    int flag = 1;
    if (ctr1 % 2 != 0) flag = 0;
    if (ctr2 % 2 != 0 && ctr1 == 0) flag = 0;
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
