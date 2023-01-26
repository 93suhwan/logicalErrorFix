#include <bits/stdc++.h>
using namespace std;
long long t, n, m, k, l, kol, lok, kol2;
string s, s1, s2, s3, s4, s5, s6, s10, s9;
int main() {
  cin >> t;
  while (t--) {
    cin >> s >> s1;
    s5 = s;
    s6 = s1;
    s2.clear();
    s3.clear();
    s4.clear();
    s9.clear();
    for (int i = s.size() - 1; i >= 0; i--) {
      for (int j = s1.size() - 1; j >= 0; j--) {
        if (s[i] <= s1[j] && s[i] >= '0' && s[i] <= '9' && s1[j] >= '0' &&
            s1[j] <= '9') {
          s2 += char(int(s1[j]) - int(s[i]) + 48);
          s1[j] = '!';
          s[i] = '!';
        } else if (s[i] > s1[j] && s[i] >= '0' && s[i] <= '9' && s1[j] >= '0' &&
                   s1[j] <= '9' && s1[j - 1] >= '0' && s1[j - 1] <= '9') {
          if ((int(s1[j]) - 48) + ((int(s1[j - 1]) - 48) * 10) -
                  (int(s[i]) - 48) >
              9) {
            s2 += char(((int(s1[j]) - 48) + ((int(s1[j - 1]) - 48) * 10) -
                        (int(s[i]) - 48)) /
                           10 +
                       48);
            s2 += char(((int(s1[j]) - 48) + ((int(s1[j - 1]) - 48) * 10) -
                        (int(s[i]) - 48)) %
                           10 +
                       48);
            s1[j] = '!';
            s1[j - 1] = '!';
            s[i] = '!';
          } else {
            s2 += char((int(s1[j]) - 48) + ((int(s1[j - 1]) - 48) * 10) -
                       (int(s[i]) - 48) + 48);
            s1[j] = '!';
            s1[j - 1] = '!';
            s[i] = '!';
          }
        }
      }
    }
    for (int i = 0; i < s1.size(); i++) {
      if (s1[i] != '!') {
        s2 += s1[i];
      }
    }
    reverse(s2.begin(), s2.end());
    l = s2.size();
    k = s5.size();
    if (k != l && min(k, l) == k) {
      for (int i = 0; i < s5.size(); i++) {
        s9 += s2[i];
      }
    } else if (k != l && min(k, l) == l) {
      for (int i = 0; i < s2.size(); i++) {
        s9 += s5[i];
      }
    }
    for (int i = 0; i < min(k, l); i++) {
      s10 = to_string((int(s2[s2.size() - i - 1]) - 48) +
                      (int(s5[s5.size() - i - 1]) - 48));
      if (s10.size() >= 2) {
        reverse(s10.begin(), s10.end());
      }
      s9 += s10;
    }
    reverse(s9.begin(), s9.end());
    if (s9 == s6) {
      for (int i = 0; i < s2.size(); i++) {
        if (s2[i] == '0') {
          s2[i] = '!';
        } else {
          break;
        }
      }
      for (int i = 0; i < s2.size(); i++) {
        if (s2[i] != '!') {
          s4 += s2[i];
        }
      }
      cout << s4 << endl;
    } else {
      cout << "-1\n";
    }
  }
}
