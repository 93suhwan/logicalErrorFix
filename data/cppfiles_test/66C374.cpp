#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int c = 1;
    int count = 0;
    if (n == 1)
      cout << 1 << "\n";
    else {
      while (true) {
        if (!(c % 3 == 0 || c % 10 == 3)) count++;
        if (count == n) break;
        c++;
      }
      cout << c << "\n";
    }
  }
}
