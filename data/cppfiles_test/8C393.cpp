#include <bits/stdc++.h>
int t;
long long n;
using namespace std;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    if (n % 3 == 0) {
      cout << n / 3 << ' ' << n / 3 << endl;
    } else if (n % 3 == 1) {
      cout << n / 3 + 1 << ' ' << n / 3 << endl;
    } else {
      cout << n / 3 << ' ' << n / 3 + 1 << endl;
    }
  }
}
