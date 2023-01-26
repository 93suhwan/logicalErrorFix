#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long c, d;
    cin >> c >> d;
    if (c % 2 == d % 2) {
      if (c == d) {
        if (c == 0)
          cout << "0" << endl;
        else
          cout << "1" << endl;
      } else {
        cout << "2" << endl;
      }
    } else
      cout << "-1" << endl;
  }
  return 0;
}
