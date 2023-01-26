#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  long long n = s.size();
  if (s[0] == '0') {
    long long i = 1;
    while (i < n && (s[i] == '0' || s[i] == '_' || s[i] == 'X')) i++;
    cout << (i == n) ? 1 : 0 << '\n';
    return 0;
  }
  if (n == 1) {
    if (s[0] == '_' || s[0] == 'X')
      cout << 1 << '\n';
    else
      cout << 0 << '\n';
    return 0;
  }
  bool x = false;
  long long count = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'X')
      x = true;
    else if (s[i] == '_')
      count++;
  }
  long long ans = pow(10, count + x);
  if (s[0] == '_' || s[0] == 'X') ans *= .9;
  string s1 = s.substr(n - 2, 2);
  if (s1[0] != '_' && s1[1] != '_' && s1[0] != 'X' && s1[1] != 'X') {
    cout << (stoi(s1) % 25 ? 0 : ans) << '\n';
  } else if (s1[0] != '_' && s1[0] != 'X') {
    if (s1[0] == '0' || s1[0] == '2' || s1[0] == '5' || s1[0] == '7')
      cout << ans / 10 << '\n';
    else
      cout << 0 << '\n';
  } else if (s1[1] != '_' && s1[1] != 'X') {
    if ((s1[1] - '0') % 5)
      cout << 0 << '\n';
    else
      cout << ans * .9 << '\n';
  } else {
    if (s1[0] == 'X' && s1[1] == 'X') {
      if (s[0] != 'X')
        cout << ans / 10 << '\n';
      else
        cout << 0 << '\n';
    } else
      cout << ans / 100 * 4 << '\n';
  }
}
