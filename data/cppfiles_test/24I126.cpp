#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n == 1) {
      cout << 0;
    } else if (n != 1 and n < 10) {
      cout << 1;
    } else {
      cout << n / 10;
    }
    cout << endl;
  }
  return 0;
}
