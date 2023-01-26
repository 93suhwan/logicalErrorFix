#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    scanf("\n");
    int ans = 0;
    char ch;
    while (n--) {
      cin >> ch;
      if (ch == '0') continue;
      ans += ch - '0';
      if (n) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
