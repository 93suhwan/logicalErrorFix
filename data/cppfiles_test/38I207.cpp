#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long s, m, l;
    if (n <= 6)
      cout << "15" << endl;
    else if (n % 6 == 0) {
      long long x;
      x = n / 6;
      cout << x * 15 << endl;
    } else if (n % 10 == 0) {
      long long x;
      x = n / 10;
      cout << x * 25 << endl;
    } else if (n % 8 == 0) {
      long long x;
      x = n / 8;
      cout << x * 20 << endl;
    } else if (n % 10 <= 6) {
      long long x = n / 10;
      x = x * 25;
      x = x + 15;
      cout << x << endl;
    } else if (n % 10 <= 8) {
      long long x = n / 10;
      x = x * 25;
      x = x + 20;
      cout << x << endl;
    } else if (n % 10 > 8) {
      long long x = n / 10;
      x++;
      cout << x * 25 << endl;
    }
  }
  return 0;
}
