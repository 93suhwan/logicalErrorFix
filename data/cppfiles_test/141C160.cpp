#include <bits/stdc++.h>
using namespace std;
string a, s, b;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> a >> s, b = "";
    int na = a.length();
    int ns = s.length();
    reverse(a.begin(), a.end()), reverse(s.begin(), s.end());
    if (na > ns) {
      cout << "-1\n";
      continue;
    }
    int ai, si = 0;
    bool no = 0;
    for (ai = 0; ai < na; ai++) {
      int fr = a[ai] - '0';
      int sc = s[si] - '0';
      if (fr == sc)
        b += '0';
      else if (fr > sc) {
        if (si + 1 >= ns) {
          no = 1;
          break;
        } else
          si++;
        int add = sc + (s[si] - '0') * 10 - fr;
        string ads = to_string(add);
        if (ads.length() > 1) {
          no = 1;
          break;
        }
        b += ads[0];
      } else {
        int add = sc - fr;
        string ads = to_string(add);
        for (char c : ads) b += c;
      }
      si++;
    }
    for (int i = si; i < ns; i++) b += s[i];
    reverse(b.begin(), b.end());
    if (no)
      cout << "-1\n";
    else {
      bool prn = 0;
      for (int i = 0; i < b.length(); i++) {
        if (b[i] != '0') prn = 1;
        if (prn) cout << b[i];
      }
      cout << '\n';
    }
  }
}
