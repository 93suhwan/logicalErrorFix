#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    if (s[0] != s[(int)s.size() - 1]) s[(int)s.size() - 1] = s[0];
    cout << s << endl;
  }
  return 0;
}
