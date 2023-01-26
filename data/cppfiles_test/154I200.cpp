#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, temp;
    cin >> a >> b >> c;
    temp = max(a, b);
    temp = max(temp, c);
    if (temp == a + b)
      cout << "YES" << endl;
    else if (temp == b + c)
      cout << "YES" << endl;
    else if (temp == a + c)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
