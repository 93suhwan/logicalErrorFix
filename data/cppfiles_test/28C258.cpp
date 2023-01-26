#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    a = a % 2;
    b = b % 2;
    c = c % 2;
    if (a == 1 && b == 1 && c == 1) {
      cout << "0\n";
    } else if ((a == 1 && b == 1 && c == 0)) {
      cout << "1\n";
    } else if ((a == 1 && b == 0 && c == 1)) {
      cout << "0\n";
    } else if ((a == 0 && b == 1 && c == 1)) {
      cout << "1\n";
    } else if ((a == 0 && b == 0 && c == 1)) {
      cout << "1\n";
    } else if ((a == 0 && b == 1 && c == 0)) {
      cout << "0\n";
    } else if ((a == 1 && b == 0 && c == 0)) {
      cout << "1\n";
    } else {
      cout << "0\n";
    }
  }
  return 0;
}
