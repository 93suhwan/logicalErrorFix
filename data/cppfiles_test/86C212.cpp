#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int t, n;
long long cnt, ans;
string s, c;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> s >> c;
    n = s.size();
    ans = cnt = 0;
    bool flag = 0, ff1 = 1, ff2 = 1, f0 = 1, f00 = 1;
    for (int i = 0; i < n; i++) {
      if (s[i] != c[i])
        ans += 2, flag = 0;
      else if (s[i] == '1' && c[i] == '1') {
        flag = 1;
      } else {
        if (flag)
          ans += 2, flag = 0;
        else {
          if (i != n - 1 && s[i + 1] == '1' && c[i + 1] == '1') {
            ans += 2;
            i++;
          } else
            ans++;
        }
      }
    }
    flag = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] != c[i])
        cnt += 2, flag = 0;
      else if (s[i] == '1' && c[i] == '1') {
        flag = 1;
      } else {
        if (flag)
          cnt += 2, flag = 0;
        else {
          if (i && s[i - 1] == '1' && c[i - 1] == '1') {
            cnt += 2;
            i--;
          } else
            cnt++;
        }
      }
    }
    cout << max(ans, cnt) << endl;
  }
  return 0;
}
