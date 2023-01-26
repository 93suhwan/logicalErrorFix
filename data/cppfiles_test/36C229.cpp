#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << 'a' << '\n';
      continue;
    }
    for (int i = 1; i <= n / 2; ++i) {
      cout << 'a';
    }
    if (n & 1) {
      cout << "yz";
    } else {
      cout << 'z';
    }
    for (int i = 1; i <= n / 2 - 1; ++i) {
      cout << 'a';
    }
    cout << '\n';
  }
  return 0;
}
