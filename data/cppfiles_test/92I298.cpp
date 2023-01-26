#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    int ab = 0, ba = 0;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == 'b' && s[i - 1] == 'a') {
        ab++;
      } else if (s[i] == 'a' && s[i - 1] == 'b') {
        ba++;
      }
    }
    int diff = ab - ba;
    if (diff == 0) {
      cout << s << endl;
    } else if (diff > 0) {
      int cnt1 = 0;
      for (int i = 1; i < s.size(); ++i) {
        if (s[i] == 'b' && s[i - 1] == 'a') {
          s[i - 1] = 'b';
          cnt1++;
          if (cnt1 == diff) break;
        }
      }
      cout << s << endl;
    } else if (diff < 0) {
      int cnt2 = 0;
      for (int i = 1; i < s.size(); ++i) {
        if (s[i] == 'a' && s[i - 1] == 'b') {
          s[i - 1] = 'a';
          cnt2--;
          if (cnt2 == diff) break;
        }
      }
      cout << s << endl;
    }
  }
  return 0;
}
