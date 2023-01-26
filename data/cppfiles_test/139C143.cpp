#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    queue<char> q;
    if (s.length() % 2 != 0)
      cout << "NO" << endl;
    else {
      string s1 = "";
      string s2 = "";
      for (int i = 0; i < s.length() / 2; i++) {
        s1 += s[i];
      }
      for (int i = s.length() / 2; i < s.length(); i++) {
        s2 += s[i];
      }
      if (s1 == s2)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
