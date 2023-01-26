#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)2e5;
int t, n, chk[maxn], s[maxn];
string s1, s2;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s1;
    cin >> s2;
    int cnt1 = 0;
    int cnt0 = 0;
    int cnt10 = 0;
    for (int i = 0; i < n; ++i) {
      chk[i] = 0;
      if (s1[i] == '0' && s2[i] == '0')
        ++cnt0;
      else {
        if (s1[i] == '1' && s2[i] == '1')
          ++cnt1;
        else
          ++cnt10;
      }
    }
    if (!cnt10) {
      if (!cnt1)
        cout << n << '\n';
      else {
        if (!cnt0)
          cout << 0 << '\n';
        else {
          int ans = 0;
          for (int i = 0; i < n; ++i) {
            if (chk[i]) continue;
            chk[i] = 1;
            if (s1[i] == '0') {
              if (s1[i - 1] == '1' && chk[i - 1] == 0) {
                chk[i - 1] = 1;
                ans += 2;
              } else {
                if (s1[i + 1] == '1' && chk[i + 1] == 0) {
                  ans += 2;
                  chk[i + 1] = 1;
                } else
                  ans += 1;
              }
            }
            if (s1[i] == '1') {
              if (s1[i - 1] == '0' && chk[i - 1] == 0) {
                chk[i - 1] = 1;
                ans += 2;
              } else {
                if (s1[i + 1] == '0' && chk[i + 1] == 0) {
                  ans += 2;
                  chk[i + 1] = 1;
                }
              }
            }
          }
          cout << ans << '\n';
        }
      }
      continue;
    }
    for (int i = 0; i < n; ++i) {
      chk[i] = 0;
      if (s1[i] == '0' && s2[i] == '0')
        s[i] = 1;
      else {
        if (s1[i] == '1' && s2[i] == '1')
          s[i] = 0;
        else
          s[i] = 2;
      }
    }
    int ans = 0;
    chk[n] = 1;
    for (int i = 0; i < n; ++i) {
      if (chk[i]) continue;
      chk[i] = 1;
      if (s[i] == 2) {
        ans += 2;
        continue;
      }
      if (s[i] == 1) {
        if (s[i - 1] == 0 && chk[i - 1] == 0) {
          chk[i - 1] = 1;
          ans += 2;
        } else {
          if (s[i + 1] == 0 && chk[i + 1] == 0) {
            ans += 2;
            chk[i + 1] = 1;
          } else
            ans += 1;
        }
      }
      if (s[i] == 0) {
        if (s[i - 1] != 0 && chk[i - 1] == 0) {
          chk[i - 1] = 1;
          ans += 2;
        } else {
          if (s[i + 1] != 0 && chk[i + 1] == 0) {
            ans += 2;
            chk[i + 1] = 1;
          }
        }
      }
    }
    cout << ans << '\n';
  }
}
