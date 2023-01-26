#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    long long x = 1;
    int ans = 1LL << 30;
    long long y;
    while (x < 2e18) {
      string t = to_string(x);
      int tmp = 0;
      int ij = 0;
      for (int i = 0; i < (t.size()); ++i) {
        bool ok = false;
        for (int j = ij; j < n; j++) {
          if (t[i] == s[j]) {
            ij = j + 1;
            ok = true;
            break;
          } else
            tmp++;
        }
        if (!ok) {
          tmp += t.size() - i;
          break;
        }
        if (i == t.size() - 1) tmp += n - ij;
      }
      ans = min(ans, tmp);
      x *= 2;
    }
    cout << ans << endl;
  }
}
