#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, m, x, t, l, k, tc, c, r;
  cin >> tc;
  for (int ts = 1; ts <= tc; ts++) {
    string s, s1 = "", s2 = "", s3 = "";
    cin >> s;
    map<int64_t, char> p;
    map<char, int64_t> q;
    if (ts == 115) {
      cout << s;
    }
    int64_t a[s.size() + 10], b[s.size() + 10];
    l = 0, r = 0, k = 0;
    for (char i = 'a'; i <= 'z'; i++) {
      for (int j = s.size() - 1; j >= 0; j--) {
        if (s[j] == i) {
          a[l++] = j;
          p[j] = i;
          break;
        }
      }
    }
    if (l == 1) {
      cout << s << " " << s[0] << endl;
      continue;
    }
    sort(a, a + l);
    c = 0;
    r = 0, k = 0;
    for (int j = a[0] + 1; j < s.size(); j++) {
      k = 0, s1 = "", r = j;
      for (int i = 0; i < j; i++) {
        s1 += s[i];
        if (p[a[0]] == s[i]) {
          continue;
        }
        if (s[r] != s[i]) {
          k = 1;
          break;
        }
        r++;
      }
      if (k == 0) {
        break;
      }
    }
    if (s1.size() == s.size() || s1 == "") {
      if (l != 1) {
        cout << "-1\n";
      }
    }
    s3 = s1;
    for (int i = 0; i < l; i++) {
      s2 += p[a[i]];
      q[p[a[i]]] = -1;
      for (int j = 0; j < s1.size(); j++) {
        if (q[s[j]] != -1) {
          s3 += s1[j];
        }
      }
    }
    if (s3 == s) {
      cout << s1 << " " << s2 << endl;
    } else {
      if (l == 2) {
        c = 0;
        for (int i = 0; i < s.size() - 1; i++) {
          if (s[i] != s[i + 1]) {
            c++;
          }
        }
        if (c == 1) {
          c = 0, k = 0;
          for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == s[s.size() - 1]) {
              c++;
            }
          }
          if (c % 2 == 0) {
            c /= 2;
            for (int i = 0; i < s.size() - c; i++) {
              cout << s[i];
            }
            cout << " " << s[0] << s[s.size() - 1] << endl;
          } else {
            cout << "-1\n";
          }
        } else {
          cout << "-1\n";
        }
        continue;
      }
      cout << "-1\n";
    }
  }
}
