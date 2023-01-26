#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    if ((a == b)) {
      if (c % 2 == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else if ((a == c)) {
      if (b % 2 == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else if ((c == b)) {
      if (a % 2 == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else if ((a + c == b)) {
      cout << "YES" << endl;
    } else if ((b + c == a)) {
      cout << "YES" << endl;
    } else if ((a + b == c)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
