#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int l1, l2, l3;
    cin >> l1 >> l2 >> l3;
    if ((l1 + l2 + l3) % 2 == 0) {
      if ((l1 % 2 == 0) or (l2 % 2 == 0) or (l3 % 2 == 0)) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else {
      cout << "NO\n";
    }
  }
}
