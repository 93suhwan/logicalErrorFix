#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long int a, b, c;
    cin >> a >> b >> c;
    long int d = a + 2 * b + 3 * c;
    cout << d % 2 << endl;
  }
}
