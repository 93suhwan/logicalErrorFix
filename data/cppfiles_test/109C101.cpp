#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      ans += (s[i] - '0');
      if (s[i] != '0') ans += 1;
    }
    ans += s[n - 1] - '0';
    if (n == 1)
      cout << s[0] - '0' << endl;
    else
      cout << ans << endl;
  }
}
