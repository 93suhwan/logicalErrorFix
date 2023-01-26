#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n % 10 == 9)
      cout << n / 10 + 1 << '\n';
    else
      cout << n / 10 << '\n';
  }
  return 0;
}
