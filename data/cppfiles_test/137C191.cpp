#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if ((a == 0) || (b == 0)) return a + b;
  return gcd(min(a, b), max(a, b) % min(a, b));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int x, y;
  cin >> x >> y;
  long long int c1 = x, c2 = y;
  string s1 = "", s2 = "";
  while (x) {
    if (x % 2)
      s1 += "1";
    else
      s1 += "0";
    x /= 2;
  }
  while (y) {
    if (y % 2)
      s2 += "1";
    else
      s2 += "0";
    y /= 2;
  }
  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());
  if (c1 == c2)
    cout << "YES"
         << "\n";
  else {
    long long int ans = 0;
    if (s2.length() >= s1.length()) {
      for (long long int j = 0; j <= (s2.length() - s1.length()); j++) {
        long long int flag = 0, in1 = j, in2 = j + s1.length() - 1;
        for (long long int k = in1; k <= in2; k++) {
          if (s1[k - j] != s2[k]) {
            flag = 1;
            break;
          }
        }
        if (flag == 0) {
          long long int cn1 = 0, ff = 0;
          for (long long int j = 0; j < in1; j++) {
            if (s2[j] != '1') {
              ff = 1;
              break;
            }
          }
          for (long long int j = in2 + 1; j < s2.length(); j++) {
            if (s2[j] != '1') {
              ff = 1;
              break;
            } else
              cn1++;
          }
          if (cn1 > 0 && ff == 0) {
            ans = 1;
            break;
          }
        }
      }
      reverse(s1.begin(), s1.end());
      for (long long int j = 0; j <= (s2.length() - s1.length()); j++) {
        long long int flag = 0, in1 = j, in2 = j + s1.length() - 1;
        for (long long int k = in1; k <= in2; k++) {
          if (s1[k - j] != s2[k]) {
            flag = 1;
            break;
          }
        }
        if (flag == 0) {
          long long int cn1 = 0, ff = 0;
          for (long long int j = 0; j < in1; j++) {
            if (s2[j] != '1') {
              ff = 1;
              break;
            } else
              cn1++;
          }
          for (long long int j = in2 + 1; j < s2.length(); j++) {
            if (s2[j] != '1') {
              ff = 1;
              break;
            }
          }
          if (cn1 > 0 && ff == 0) {
            ans = 1;
            break;
          }
        }
      }
      reverse(s1.begin(), s1.end());
    }
    if (ans == 1)
      cout << "YES"
           << "\n";
    else {
      long long int i = s1.length() - 1;
      while (i >= 0) {
        if (s1[i] == '0') {
          s1.pop_back();
          i--;
        } else
          break;
      }
      if (s2.length() >= s1.length()) {
        for (long long int j = 0; j <= (s2.length() - s1.length()); j++) {
          long long int flag = 0, in1 = j, in2 = j + s1.length() - 1;
          for (long long int k = in1; k <= in2; k++) {
            if (s1[k - j] != s2[k]) {
              flag = 1;
              break;
            }
          }
          if (flag == 0) {
            long long int ff = 0;
            for (long long int j = 0; j < in1; j++) {
              if (s2[j] != '1') {
                ff = 1;
                break;
              }
            }
            for (long long int j = in2 + 1; j < s2.length(); j++) {
              if (s2[j] != '1') {
                ff = 1;
                break;
              }
            }
            if (ff == 0) {
              ans = 1;
              break;
            }
          }
        }
      }
      if (ans == 1)
        cout << "YES"
             << "\n";
      else {
        reverse(s1.begin(), s1.end());
        if (s2.length() >= s1.length()) {
          for (long long int j = 0; j <= (s2.length() - s1.length()); j++) {
            long long int flag = 0, in1 = j, in2 = j + s1.length() - 1;
            for (long long int k = in1; k <= in2; k++) {
              if (s1[k - j] != s2[k]) {
                flag = 1;
                break;
              }
            }
            if (flag == 0) {
              long long int ff = 0;
              for (long long int j = 0; j < in1; j++) {
                if (s2[j] != '1') {
                  ff = 1;
                  break;
                }
              }
              for (long long int j = in2 + 1; j < s2.length(); j++) {
                if (s2[j] != '1') {
                  ff = 1;
                  break;
                }
              }
              if (ff == 0) {
                ans = 1;
                break;
              }
            }
          }
        }
        if (ans == 1)
          cout << "YES"
               << "\n";
        else
          cout << "NO"
               << "\n";
      }
    }
  }
  return 0;
}
