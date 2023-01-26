#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    a += 2 * b;
    a += 3 * c;
    cout << a % 2 << endl;
  }
}
