#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n <= 8)
      cout << 0 << '\n';
    else if (n == 9 || n == 10)
      cout << 1 << '\n';
    else {
      if (n % 10 == 9)
        cout << (n / 10) + 1 << '\n';
      else
        cout << n / 10 << '\n';
    }
  }
}
