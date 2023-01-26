#include <bits/stdc++.h>
using namespace std;
int pos(string str, char x) {
  int i;
  for (i = 0; i < str.length(); i++) {
    if (str[i] == x) break;
  }
  return i + 1;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string alphabets, str;
    cin >> alphabets >> str;
    int ans = 0;
    if (str.length() == 0) {
      cout << ans << endl;
    }
    for (int i = 0; i < str.length() - 1; i++) {
      ans += abs(pos(alphabets, str[i]) - pos(alphabets, str[i + 1]));
    }
    cout << ans << endl;
  }
  return 0;
}
