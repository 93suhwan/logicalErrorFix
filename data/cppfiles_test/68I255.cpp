#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    int a = 1;
    int x = 1;
    int i = 1;
    while (x + a <= k) {
      x += a;
      a += 2;
      i++;
    }
    int m = k - x + 1;
    if (m <= i)
      cout << m << " " << i << endl;
    else
      cout << i << " " << m << endl;
  }
  return 0;
}
