#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int l1, l2, l3;
    cin >> l1 >> l2 >> l3;
    if ((l1 == l2) and (l2 == l3)) {
      if (l1 % 2 == 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else if ((l1 != l2) and (l2 != l3) and (l3 != l1)) {
      long long int a = max(l1, max(l2, l3));
      long long int b = min(l1, min(l2, l3));
      long long int c = (l1 + l2 + l3) - a - b;
      if (a == b + c) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else {
      if (l1 == l2) {
        if (l3 % 2 == 0) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      } else if (l2 == l3) {
        if (l1 % 2 == 0) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      } else if (l1 == l3) {
        if (l2 % 2 == 0) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      } else {
        cout << "NO\n";
      }
    }
  }
}
