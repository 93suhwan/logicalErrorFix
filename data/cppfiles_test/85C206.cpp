#include <bits/stdc++.h>
using namespace std;
string s;
long long ans, i, n, j;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> s;
    ans = 0;
    for (j = 0; j < s.size(); j++) {
      if ((j == 0 && s[j] == '0') || (s[j - 1] == '1' && s[j] == '0')) {
        ans++;
      }
    }
    if (ans < 3) {
      cout << ans << endl;
    } else {
      cout << 2 << endl;
    }
  }
  return 0;
}
