#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int z = 0, c = 0;
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s2.size(); i++) {
      if (i == 0) {
        for (int x = 0; x < s1.size(); x++) {
          if (s1[x] == s2[i]) {
            z = x;
            break;
          }
        }
      } else {
        for (int x = 0; x < s1.size(); x++) {
          if (s1[x] == s2[i]) {
            c += abs(x - z);
            z = x;
            break;
          }
        }
      }
    }
    cout << c << endl;
  }
  return 0;
}
