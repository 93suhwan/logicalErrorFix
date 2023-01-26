#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int ttt;
  cin >> ttt;
  while (ttt--) {
    vector<int> l(3);
    cin >> l[0] >> l[1] >> l[2];
    sort(l.begin(), l.end());
    if (l[0] + l[1] == l[2])
      cout << "YES"
           << "\n";
    else if ((l[0] == l[1] && l[2] % 2 == 0) || (l[0] % 2 == 0 && l[1] == l[2]))
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}
