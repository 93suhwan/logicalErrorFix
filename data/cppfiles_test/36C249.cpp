#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int q = 0; q < t; ++q) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << 'a' << "\n";
      continue;
    }
    if (n == 2) {
      cout << "ab"
           << "\n";
      continue;
    }
    for (int i = 0; i < n / 2; ++i) {
      cout << 'a';
    }
    cout << 'b';
    for (int i = 0; i < n / 2 - 1; ++i) {
      cout << 'a';
    }
    if (n % 2 == 1) cout << 'c';
    cout << "\n";
  }
}
