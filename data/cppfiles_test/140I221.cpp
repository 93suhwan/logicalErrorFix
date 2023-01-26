#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int count = 0;
  while (t--) {
    int x;
    cin >> x;
    int a = sqrt(x);
    int b = cbrt(x);
    if (a * a == x) {
      count++;
    } else if (b * b * b == x) {
      count++;
    }
    cout << count << endl;
  }
}
