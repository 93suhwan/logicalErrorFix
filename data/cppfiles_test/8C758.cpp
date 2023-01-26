#include <bits/stdc++.h>
using namespace std;
int main() {
  long t;
  cin >> t;
  while (t != 0) {
    long n;
    cin >> n;
    long c1, c2;
    c1 = c2 = n / 3;
    n = n - (c1 + 2 * c2);
    if (n != 0) {
      if (n % 2 == 1)
        c1++;
      else
        c2++;
    }
    cout << c1 << "  " << c2 << "\n";
    t--;
  }
}
