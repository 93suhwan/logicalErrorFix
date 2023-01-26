#include <bits/stdc++.h>
using namespace std;
string solve() {
  int l1, l2, l3;
  cin >> l1 >> l2 >> l3;
  if (l1 + l2 == l3 || l2 + l3 == l1 || l3 + l1 == l2)
    return "yes";
  else if ((l1 % 2 == 0 && l2 == l3) || (l2 % 2 == 0 && l3 == l1) ||
           (l3 % 2 == 0 && l1 == l2))
    return "yes";
  return "no";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << "\n";
  }
}
