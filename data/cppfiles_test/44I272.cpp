#include <bits/stdc++.h>
using namespace std;
bool solve() {
  int c, d, dis;
  cin >> c >> d;
  dis = abs(c - d);
  if (dis == 0)
    cout << "0\n";
  else if (dis % 2 == 0)
    cout << "2\n";
  else
    cout << "-1\n";
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i = i + 1) {
    solve();
  }
}
