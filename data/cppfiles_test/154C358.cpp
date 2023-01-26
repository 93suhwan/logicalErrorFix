#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int l1, l2, l3;
    cin >> l1 >> l2 >> l3;
    if (l1 == (l2 + l3) || l2 == (l1 + l3) || l3 == (l1 + l2)) {
      cout << "YES"
           << "\n";
      continue;
    } else if ((l1 == l2 && l3 % 2 == 0) || ((l1 == l3) && l2 % 2 == 0) ||
               (l2 == l3 && l1 % 2 == 0)) {
      cout << "YES"
           << "\n";
      continue;
    } else {
      cout << "NO"
           << "\n";
      continue;
    }
  }
}
