#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s[0] == s[(int)s.size() - 1]) {
      cout << s << '\n';
    } else {
      s[0] = s[(int)s.size() - 1];
      cout << s << '\n';
    }
  }
  return 0;
}
