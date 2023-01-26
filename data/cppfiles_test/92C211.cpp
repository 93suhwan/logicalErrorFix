#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s[0] != s[s.length() - 1]) s[0] = s[s.length() - 1];
    cout << s << endl;
  }
  return 0;
}
