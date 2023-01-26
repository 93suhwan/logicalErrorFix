#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int l1, l2, l3;
    cin >> l1 >> l2 >> l3;
    long long int a, b, c;
    c = min(l1, min(l2, l3));
    a = max(l1, max(l2, l3));
    b = (l1 + l2 + l3) - a - c;
    if ((a == (b + c)) and (a % 2 == 0)) {
      cout << "YES"
           << "\n";
    } else if ((a == b) and (c % 2 == 0)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
