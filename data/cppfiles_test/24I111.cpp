#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n > 1) {
      int sum = 0;
      while (n != 0) {
        sum += n % 10;
        n = n / 10;
      }
      int big = 0, p = n + 1;
      while (p != 0) {
        big += p % 10;
        p = p / 10;
      }
      if ((big > sum) || n == 1) {
        cout << 1 << endl;
      }
    }
  }
  return 0;
}
