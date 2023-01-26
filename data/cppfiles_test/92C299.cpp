#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    s[0] = s[s.length() - 1];
    cout << s << endl;
  }
  return 0;
}
