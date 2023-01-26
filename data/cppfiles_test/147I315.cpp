#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int i, j, k, a, b, n, t, flag, cur;
  cin >> t;
  while (t--) {
    flag = 1;
    cur = 1;
    string s;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == 'N') flag = 0;
    }
    if (flag && s[n - 1] == 'N')
      cout << "NO"
           << "\n";
    else
      cout << "YES"
           << "\n";
  }
}
