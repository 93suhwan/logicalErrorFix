#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int b = 0;
    int c = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'B') {
        b++;
      } else {
        c++;
      }
    }
    if (c <= b) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
