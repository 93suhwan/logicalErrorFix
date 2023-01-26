#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s = "";
    for (int i = 0; i < n - 2; i++) {
      string temp;
      cin >> temp;
      s += temp;
    }
    string ans = "";
    ans += s[0];
    int c = 0;
    for (int i = 1; i < s.length() - 1; i++) {
      if (s[i] == s[i + 1]) {
        ans += s[i];
        i += 1;
      } else {
        c = 1;
        ans += s[i];
        ans += s[i + 1];
        i = i + 1;
      }
    }
    int len = s.length() - 1;
    ans += s[len];
    if (c == 0) {
      ans += "a";
    }
    cout << ans << endl;
  }
}
