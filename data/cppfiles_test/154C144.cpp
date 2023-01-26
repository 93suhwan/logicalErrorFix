#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, temp, s, total, ss;
    cin >> a >> b >> c;
    temp = max(a, b);
    temp = max(temp, c);
    s = min(a, b);
    s = min(s, c);
    total = a + b + c;
    ss = total - temp - s;
    if (temp == (s + ss))
      cout << "YES" << endl;
    else if ((temp == ss) && (s % 2 == 0))
      cout << "YES" << endl;
    else if ((s == ss) && (temp % 2 == 0))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
