#include <bits/stdc++.h>
using namespace std;
int q;
string s, t;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> q;
  while (q--) {
    cin >> s;
    cin >> t;
    string ans = "NO";
    for (int i = 0; i < s.size(); ++i)
      if (ans == "YES")
        break;
      else {
        string s1 = "";
        for (int j = i; j < min(i + t.size(), s.size()); ++j)
          if (ans == "YES")
            break;
          else {
            s1 += s[j];
            if (s1.size() + j >= t.size()) {
              if (s1 == t) {
                ans = "YES";
                break;
              }
              for (int k = j - 1; k >= 0; --k) {
                s1 += s[k];
                if (s1.size() == t.size()) break;
              }
              if (s1 == t) {
                ans = "YES";
                break;
              }
              while (s1.size() != j - i + 1) s1.erase(s1.size() - 1, 1);
            }
          }
      }
    cout << ans << '\n';
  }
  return 0;
}
