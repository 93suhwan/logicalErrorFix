#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int t, a[30], ans, sum1;
string s;
int main() {
  cin >> t;
  while (t--) {
    memset(a, 0, sizeof(a));
    ans = sum1 = 0;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
      a[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (a[i] >= 2) ans++;
      if (a[i] == 1) sum1++;
    }
    ans += sum1 / 2;
    cout << ans << endl;
  }
  return 0;
}
