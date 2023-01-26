#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int a, b, c;
    cin >> a >> b >> c;
    a %= 2;
    b %= 2;
    c %= 2;
    cout << abs(abs(c * 3 - b * 2) - a) << endl;
  }
}
