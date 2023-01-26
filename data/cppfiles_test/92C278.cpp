#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  cin.get();
  while (t--) {
    char s[101];
    cin.getline(s, 101);
    if (s[0] == s[strlen(s) - 1])
      cout << s << '\n';
    else {
      s[0] = s[strlen(s) - 1];
      cout << s << '\n';
    }
  }
  return 0;
}
