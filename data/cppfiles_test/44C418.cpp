#include <bits/stdc++.h>
using namespace std;
void solve(int c, int d) {
  int a = 0;
  int b = 0;
  if (c == 0 && d == 0) {
    cout << "0" << endl;
  } else if (((c - d) % 2) != 0) {
    cout << "-1" << endl;
  } else if (c == d) {
    cout << "1" << endl;
  } else {
    cout << "2" << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int c, d;
    cin >> c >> d;
    solve(c, d);
  }
  return 0;
}
