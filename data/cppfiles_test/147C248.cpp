#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int x = 0, a = s.length();
    for (int i = 0; i < a; i++) {
      if (s[i] == 'N') {
        ++x;
      }
    }
    if (x == 1) {
      cout << "NO\n";
    } else {
      cout << "YES" << endl;
    }
  }
}
