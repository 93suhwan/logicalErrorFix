#include <bits/stdc++.h>
using namespace std;
void Solve() {
  long long int c, d;
  cin >> c >> d;
  if ((c + d) % 2 != 0) {
    cout << "-1" << endl;
    return;
  }
  if (c < 0 && d < 0) {
    cout << "-1" << endl;
    return;
  }
  if (c == 0 && d == 0) {
    cout << "0" << endl;
    return;
  }
  if (c == d) {
    cout << "1" << endl;
    return;
  }
  cout << "2" << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  unsigned long long int T;
  cin >> T;
  while (T--) {
    Solve();
  }
  return 0;
}
