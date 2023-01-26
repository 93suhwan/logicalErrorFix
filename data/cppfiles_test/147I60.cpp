#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int i, j, k, a, b, n, t, flag, cur, flag2;
  cin >> t;
  while (t--) {
    flag = flag2 = 1;
    cur = 1;
    string s;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == 'N') flag = 0;
    }
    for (int i = 1; i <= n - 1; i++)
      if (s[i] == 'N') flag2 = 0;
    if (flag && s[n - 1] == 'N')
      cout << "NO"
           << "\n";
    else if (flag2 && s[0] == 'N')
      cout << "NO"
           << "\n";
    else
      cout << "YES"
           << "\n";
  }
}
