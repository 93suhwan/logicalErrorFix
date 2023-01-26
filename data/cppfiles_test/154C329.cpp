#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, l[3], max;
  cin >> t;
  while (t--) {
    string ans = "NO";
    cin >> l[0] >> l[1] >> l[2];
    sort(l, l + 3);
    if (l[2] == (l[1] + l[0])) {
      ans = "YES";
    } else if ((l[2] == l[1]) && (l[0] % 2 == 0)) {
      ans = "YES";
    } else if ((l[0] == l[1]) && (l[2] % 2 == 0)) {
      ans = "YES";
    }
    cout << ans << endl;
  }
  return 0;
}
