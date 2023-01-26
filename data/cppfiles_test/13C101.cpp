#include <bits/stdc++.h>
using namespace std;
int t, ans;
string s;
int main() {
  cin >> t;
  while (t--) {
    cin >> s;
    ans = 0;
    for (int i = 0; i < s.length(); i++)
      if (s[i] == 'B') ans++;
    if (ans * 2 == s.length())
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
