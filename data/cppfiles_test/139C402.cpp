#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (; t > 0; t--) {
    string s;
    cin >> s;
    if ((s.size() & 1) ||
        s.substr(0, s.size() / 2) != s.substr(s.size() / 2, s.size() / 2)) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}
