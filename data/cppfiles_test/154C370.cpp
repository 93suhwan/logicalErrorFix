#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int l1, l2, l3;
    cin >> l1 >> l2 >> l3;
    string ans = "NO";
    if (l1 + l2 == l3 || l1 + l3 == l2 || l2 + l3 == l1)
      ans = "YES";
    else if (l1 == l2 && l3 % 2 == 0)
      ans = "YES";
    else if (l1 == l3 && l2 % 2 == 0)
      ans = "YES";
    else if (l3 == l2 && l1 % 2 == 0)
      ans = "YES";
    cout << ans << endl;
  }
  return 0;
}
