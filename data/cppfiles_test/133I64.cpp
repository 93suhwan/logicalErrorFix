#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  string s[101];
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n - 2; i++) {
      cin >> s[i];
    }
    if (n - 2 == 1) {
      cout << s[0] + "a"
           << "\n";
    } else {
      cout << s[0][1] << s[1][0] << "\n";
    }
  }
  return 0;
}
