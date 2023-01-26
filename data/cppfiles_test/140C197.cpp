#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    int count = 0;
    int a = sqrt(x);
    int b = cbrt(x);
    int c = (int)(sqrt(cbrt(x)));
    count = a + b - c;
    cout << count << endl;
  }
}
