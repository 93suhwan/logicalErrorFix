#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n % 3 == 0) {
      cout << n / 3 << " " << n / 3 << endl;
    } else if (n % 3 == 1) {
      cout << n - ((n / 3) * 2) << " ";
      cout << n / 3 << endl;
    } else {
      n -= 2;
      cout << n / 3 << " " << n / 3 + 1 << endl;
    }
  }
}
