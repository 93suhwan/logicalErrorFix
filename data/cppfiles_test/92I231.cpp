#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int cnt = 0, cnt1 = 0;
    for (int i = 0; i < s.length(); i++)
      if (s[i] == 'a')
        cnt++;
      else
        cnt1++;
    if (cnt < cnt1) {
      for (int i = 0; i < s.length(); i++) cout << "b";
    } else {
      for (int i = 0; i < s.length(); i++) cout << "a";
    }
    cout << nl;
  }
  return 0;
}
