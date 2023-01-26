#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int t;
  cin >> t;
  while (t--) {
    long long int a, b, c, temp;
    cin >> a >> b >> c;
    temp = a + 2 * b + 3 * c;
    cout << temp % 2 << endl;
  }
}
