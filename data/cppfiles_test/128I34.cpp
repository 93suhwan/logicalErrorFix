#include <bits/stdc++.h>
using namespace std;
int main() {
  int tests;
  cin >> tests;
  while (tests--) {
    long long int n;
    cin >> n;
    if (n % 2) {
      cout << (n - 1) / 2 + 1 << " " << (n - 1) / 2 - 1 << 1 << " ";
    } else {
      cout << (n - 1) / 2 << " " << (n - 1) / 2 + 1 << 1 << " ";
    }
    return 0;
  }
}
