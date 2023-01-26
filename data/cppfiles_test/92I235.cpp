#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  {
    while (n--) {
      string s;
      cin >> s;
      int k1 = 0, k2 = 0;
      int l = s.size();
      for (int i = 0; i < l; i++) {
        if (s[i] == 'a' && s[i + 1] == 'b') {
          k1++;
        }
        if (s[i] == 'b' && s[i + 1] == 'a') k2++;
      }
      if (k1 == k2)
        cout << s << "\n";
      else if (k1 > k2) {
        for (int i = 0; i < l; i++) {
          if (s[i] == 'a' && s[i + 1] == 'b') {
            s[i] = 'b';
            k1--;
            if (k1 == k2) break;
          }
        }
        cout << s << "\n";
      } else {
        for (int i = 0; i < l; ++i) {
          if (s[i] == 'b' && s[i + 1] == 'a') {
            s[i] = 'a';
            k2--;
            if (k1 == k2) break;
          }
        }
        cout << s << "\n";
      }
    }
  }
}
