#include <bits/stdc++.h>
using namespace std;
vector<int> v[300005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    int n = s.length();
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'a') {
        a++;
      }
      if (s[i] == 'b') {
        b++;
      }
      if (s[i] == 'c') {
        c++;
      }
    }
    if (t == "abc") {
      t = "acb";
    } else if (t == "acb") {
      t = "abc";
    } else if (t == "bac") {
      t = "abc";
    } else if (t == "bca") {
      t = "abc";
    } else if (t == "cab") {
      t = "abc";
    } else if (t == "cba") {
      t = "abc";
    }
    if (t == "abc") {
      cout << s << endl;
      continue;
    }
    string ans = "";
    if (a > 0 && b > 0 && c > 0) {
      for (int i = 0; i < a; i++) {
        ans += 'a';
      }
      for (int i = 0; i < c; i++) {
        ans += 'c';
      }
      for (int i = 0; i < b; i++) {
        ans += 'b';
      }
      for (int i = a + b + c; i < s.length(); i++) {
        ans += s[i];
      }
      cout << ans << endl;
    } else {
      cout << s << endl;
    }
  }
}
