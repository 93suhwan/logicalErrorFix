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
    } else if (n % 6 <= 2) {
      long long x;
      x = n / 6;
      x--;
      x = x * 15;
      x += 20;
      cout << x << endl;
    } else if (n % 6 <= 4) {
      long long x;
      x = n / 6;
      x--;
      x = x * 15;
      x += 25;
      cout << x << endl;
    } else {
      long long x;
      x = n / 6;
      x++;
      x = x * 15;
      cout << x << endl;
    }
  }
  return 0;
}
