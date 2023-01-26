#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n == 1) {
      cout << "1 0" << endl;
    } else if (n == 2) {
      cout << "0 1" << endl;
    } else if (n == 5) {
      cout << "1 2" << endl;
    } else {
      long long int fir = n / 3;
      long long int mod = n % 3;
      cout << fir + mod << " " << fir << endl;
    }
  }
}
