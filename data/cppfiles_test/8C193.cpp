#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a = n / 3;
    int b = n - a;
    if (b % 2 == 0) {
      cout << a << " " << (n - a) / 2 << endl;
    } else {
      int e = a + 1;
      int d = n - e;
      cout << e << " " << d / 2 << endl;
    }
  }
}
