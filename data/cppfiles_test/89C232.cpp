#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    bool flag = true;
    for (int i = 0; i < n; i++) {
      int val = 0;
      for (int j = i + 2; j > 0 && a[i] % j == 0; j--) val++;
      if (val > i) {
        flag = false;
        break;
      }
    }
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
