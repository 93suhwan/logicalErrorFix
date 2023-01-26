#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int i, j, k, a, b, n, t, flag, cur, flag2;
  cin >> t;
  while (t--) {
    flag = flag2 = 0;
    cur = 1;
    string s;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] == 'N') flag++;
    }
    if (flag == 1)
      cout << "NO"
           << "\n";
    else
      cout << "YES"
           << "\n";
  }
}
