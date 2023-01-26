#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, i, sum = 0;
    string s;
    cin >> n;
    cin >> s;
    for (i = 0; i < n - 1; i++) {
      m = s[i] - 48;
      if (m > 0) {
        sum = sum + m + 1;
      }
    }
    m = s[n - 1] - 48;
    cout << sum + m << endl;
  }
  return 0;
}
