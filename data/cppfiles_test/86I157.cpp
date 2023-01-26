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
        else
          ans++;
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
        else
          cnt++;
      }
    }
    int i = 0, j = n - 1;
    while (s[i] == '1' && i < n) i++;
    while (s[j] == '1' && j >= 0) j--;
    if (!i && j == n - 1) ff1 = 0;
    for (i; i <= j; i++)
      if (s[i] == '1') {
        ff1 = 0;
        break;
      }
    i = 0, j = n - 1;
    while (c[i] == '1' && i < n) i++;
    while (c[j] == '1' && j >= 0) j--;
    if (!i && j == n - 1) ff2 = 0;
    for (i; i <= j; i++)
      if (c[i] == '1') {
        ff2 = 0;
        break;
      }
    i = 0, j = n - 1;
    while (s[i] == '0' && i < n) i++;
    while (s[j] == '0' && j >= 0) j--;
    if (!i && j == n - 1) f0 = 0;
    for (i; i <= j; i++)
      if (s[i] == '0') {
        f0 = 0;
        break;
      }
    i = 0, j = n - 1;
    while (c[i] == '0' && i < n) i++;
    while (c[j] == '0' && j >= 0) j--;
    if (!i && j == n - 1) f00 = 0;
    for (i; i <= j; i++)
      if (c[i] == '0') {
        f00 = 0;
        break;
      }
    if ((ff1 && ff2) || (f0 && f00)) ans++;
    cout << max(ans, cnt) << endl;
  }
  return 0;
}
