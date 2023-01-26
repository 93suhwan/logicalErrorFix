#include <bits/stdc++.h>
using namespace std;
int main() {
  int i;
  cin >> i;
  while (i--) {
    string str;
    cin >> str;
    string a;
    cin >> a;
    map<char, int> req;
    for (int j = 0; j < str.length(); j++) {
      req[str[j]] = j;
    }
    int ans = 0;
    int x = a.length();
    for (int j = 0; j < x - 1; j++) {
      if (req[a[j]] > req[a[j + 1]]) {
        ans += req[a[j]] - req[a[j + 1]];
      } else {
        ans += req[a[j + 1]] - req[a[j]];
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
