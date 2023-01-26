#include <bits/stdc++.h>
using namespace std;
using namespace std;
signed main() {
  int T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    long long ans = 0;
    for (long long i = 0; i < s2.size(); i++) {
      if (s2[i] == '1') {
        if (s1[i] == '0')
          ans++;
        else if (i == 0) {
          if (s1[i + 1] == '1') {
            s1[i + 1] = '0';
            ans++;
          }
        } else {
          if (s1[i - 1] == '1') {
            s1[i - 1] = '0';
            ans++;
          } else if (s1[i + 1] == '1') {
            s1[i + 1] = '0';
            ans++;
          }
        }
      }
    }
    cout << ans << endl;
  }
}
