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
    for (int i = 0; i < n - 2; i++) {
      ans += (s[i] - '0');
      if (s[i] != '0') ans += 1;
    }
    ans += s[n - 2] - '0';
    if (s[n - 2] != '0') ans += 1;
    ans += s[n - 1] - '0';
    cout << ans << endl;
  }
}
