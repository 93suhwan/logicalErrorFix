#include <bits/stdc++.h>
using namespace std;
const int maxn = 120;
int n;
int main() {
  int t;
  cin >> t;
  while (t--) {
    bool flag = true;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
      if (a[i + 1] == '1' && b[i + 1] == '1') {
        flag = false;
        break;
      }
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
