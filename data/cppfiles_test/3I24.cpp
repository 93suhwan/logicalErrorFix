#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  string s;
  cin >> s;
  long long ans = 0;
  if (s.size() == 1) {
    if (s[0] == 'X' || s[0] == '_' || s[0] == '0') {
      cout << 1 << "\n";
    } else
      cout << 0 << "\n";
  } else {
    string s1, s2, s3;
    s1 = s2 = s3 = s;
    long long n = s.size();
    long long l1 = n - 1, l2 = n - 2;
    long long ans = 0;
    if (s1[l1] == 'X' || s1[l2] == 'X') {
      for (long long i = 0; i < n; i++) {
        if (s1[i] == 'X') {
          s1[i] = '0';
        }
      }
    }
    if ((s1[l1] == '0' || s1[l1] == '_') and
        (s1[l2] == '0' || s1[l2] == '_') and s1[0] != '0') {
      long long cnt = 1;
      for (long long i = 0; i < n - 2; i++) {
        if (s1[i] == '_') {
          cnt *= (i == 0 ? 9 : 10);
        }
      }
      bool found = 0;
      for (long long i = 0; i < n; i++) {
        if (s1[i] == 'X') {
          found = 1;
          break;
        }
      }
      if (found) {
        if (s1[0] == 'X') {
          cnt *= 9;
        } else
          cnt * 10;
      }
      ans += cnt;
    }
    if (s2[l1] == '5') {
      for (long long i = 0; i < n; i++) {
        if (s2[i] == 'X') {
          s2[i] = '5';
        }
      }
    } else if (s2[l2] == 'X') {
      for (long long i = 0; i < n; i++) {
        if (s2[i] == 'X') {
          s2[i] = '2';
        }
      }
    }
    if ((s2[l1] == '5' || s2[l1] == '_') and
        (s2[l2] == '2' || s2[l2] == '_') and s2[0] != '0') {
      long long cnt = 1;
      for (long long i = 0; i < n - 2; i++) {
        if (s2[i] == '_') {
          cnt *= (i == 0 ? 9 : 10);
        }
      }
      bool found = 0;
      for (long long i = 0; i < n; i++) {
        if (s2[i] == 'X') {
          found = 1;
          break;
        }
      }
      if (found) {
        if (s2[0] == 'X') {
          cnt *= 9;
        } else
          cnt * 10;
      }
      ans += cnt;
    }
    if (s3[l1] == 'X') {
      for (long long i = 0; i < n; i++) {
        if (s3[i] == 'X') {
          s3[i] = '0';
        }
      }
    } else if (s3[l2] == 'X') {
      for (long long i = 0; i < n; i++) {
        if (s3[i] == 'X') {
          s3[i] = '5';
        }
      }
    }
    if ((s3[l1] == '0' || s3[l1] == '_') and
        (s3[l2] == '5' || s3[l2] == '_') and s3[0] != '0') {
      long long cnt = 1;
      for (long long i = 0; i < n - 2; i++) {
        if (s3[i] == '_') {
          cnt *= (i == 0 ? 9 : 10);
        }
      }
      bool found = 0;
      for (long long i = 0; i < n; i++) {
        if (s3[i] == 'X') {
          found = 1;
          break;
        }
      }
      if (found) {
        if (s3[0] == 'X') {
          cnt *= 9;
        } else
          cnt * 10;
      }
      ans += cnt;
    }
    cout << ans << "\n";
  }
  return 0;
}
