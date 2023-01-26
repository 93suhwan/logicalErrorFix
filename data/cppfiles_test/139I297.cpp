#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.length() % 2 != 0) {
      cout << "NO" << endl;
    } else {
      char x = s[0];
      int j = 1;
      for (int i = 0; i < s.length(); i++) {
        if (s[j] == x) {
          j++;
        } else {
          break;
        }
      }
      int ct = 0;
      for (int i = 0; i < s.length(); i++) {
        if (s[i] == x) {
          ct++;
        }
      }
      if (j * 2 == s.length() || ct == s.length()) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
