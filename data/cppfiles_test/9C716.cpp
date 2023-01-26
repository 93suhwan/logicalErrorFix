#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, c, d, count[26];
  string s;
  cin >> t;
  while (t--) {
    cin >> s;
    for (int i = 0; i < 26; i++) count[i] = 0;
    for (int i = 0; s[i]; i++) count[s[i] - 'a']++;
    c = d = 0;
    for (int i = 0; i < 26; i++)
      if (count[i] == 1)
        c++;
      else if (count[i] > 1)
        d++;
    cout << (d + c / 2) << endl;
  }
  return 0;
}
