#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int c, d;
  cin >> c >> d;
  if (abs(c - d) % 2)
    cout << "-1" << endl;
  else {
    if (c == d) {
      if (c == 0)
        cout << "0" << endl;
      else
        cout << "1" << endl;
    } else
      cout << "2" << endl;
  }
}
int main() {
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
