#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, s = 0;
    cin >> a >> b >> c;
    if (a % 2 == 0) s++;
    if (b % 2 == 0) s++;
    if (c % 2 == 0) s++;
    if (s == 1 || s == 3)
      cout << "YES" << endl;
    else if (s == 2)
      cout << "NO" << endl;
  }
  return 0;
}
