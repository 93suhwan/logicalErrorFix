#include <bits/stdc++.h>
using namespace std;
void init_code() {}
int main() {
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    if (a == b) {
      if (c % 2 == 0)
        cout << "YES"
             << "\n";
      else
        cout << "NO"
             << "\n";
    } else if (b == c) {
      if (a % 2 == 0)
        cout << "YES"
             << "\n";
      else
        cout << "NO"
             << "\n";
    } else if (a == c) {
      if (b % 2 == 0)
        cout << "YES"
             << "\n";
      else
        cout << "NO"
             << "\n";
    } else {
      long long int ar[5];
      ar[0] = a, ar[1] = b, ar[2] = c;
      sort(ar, ar + 3);
      if (ar[2] - ar[0] == ar[1])
        cout << "YES"
             << "\n";
      else
        cout << "NO"
             << "\n";
    }
  }
  return 0;
}
