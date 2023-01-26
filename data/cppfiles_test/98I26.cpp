#include <bits/stdc++.h>
using namespace std;
string a, s;
const int INF = 1e9;
int getID(char c) {
  for (int i = 0; i < 26; i++) {
    if (a[i] == c) {
      return i;
    }
  }
  return INF;
}
int main() {
  int t;
  cin >> t;
  cin >> a;
  while (t--) {
    getline(cin, a);
    getline(cin, s);
    int ans = 0;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] != s[i - 1]) {
        ans += abs(getID(s[i]) - getID(s[i - 1]));
      }
    }
    cout << ans << endl;
  }
  return 0;
}
