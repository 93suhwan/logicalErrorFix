#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int j = 0; j < t; j++) {
    int b, a, c;
    b = 0;
    a = 0;
    c = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      if (int(s[i]) == 66) {
        b++;
      }
      if (int(s[i]) == 65) {
        a++;
      }
      if (int(s[i]) == 67) {
        c++;
      }
    }
    if (b == a + c) {
      cout << "YES";
    } else {
      cout << "NO";
    }
  }
}
