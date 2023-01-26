#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    string a = s;
    if (s[0] == '?') s[0] = 'R';
    for (int i = 1; i < n; i++) {
      if (s[i] == '?') s[i] = 'R' + 'B' - s[i - 1];
    }
    if (a[0] != '?') {
      cout << s << "\n";
      continue;
    }
    int x = 0;
    for (int i = 1; i < n; i++)
      if (s[i] == s[i - 1]) x++;
    string s1 = s;
    s = a;
    s[0] = 'B';
    for (int i = 1; i < n; i++) {
      if (s[i] == '?') s[i] = 'R' + 'B' - s[i - 1];
    }
    int y = 0;
    for (int i = 1; i < n; i++)
      if (s[i] == s[i - 1]) y++;
    if (x < y)
      cout << s1 << "\n";
    else
      cout << s << "\n";
  }
  return 0;
}
