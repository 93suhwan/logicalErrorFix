#include <bits/stdc++.h>
const long long mod = 1000000007;
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, flag = 0;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < n; i++) {
      if (a[i] == '1' && b[i] == '1') {
        flag = 1;
      }
    }
    if (flag)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
