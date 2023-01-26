#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int s = 0;
    int a[3];
    for (int i = 0; i < 3; i++) cin >> a[i];
    sort(a, a + 3);
    if (a[0] == a[1]) {
      if (a[2] % 2 == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else if (a[1] == a[2]) {
      if (a[0] % 2 == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else if (a[0] + a[1] == a[2])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
