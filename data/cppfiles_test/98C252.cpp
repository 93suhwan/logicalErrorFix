#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  while (n--) {
    string s, t;
    cin >> s >> t;
    int c[200];
    for (int i = 0; i < 26; i++) c[s[i]] = i;
    if (t.length() == 1)
      cout << 0 << endl;
    else {
      long long ans = 0;
      for (int i = 1; i < t.length(); i++) ans += abs(c[t[i]] - c[t[i - 1]]);
      cout << ans << endl;
    }
  }
  return 0;
}
