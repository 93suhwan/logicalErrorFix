#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int k;
    cin >> k;
    int l = 0;
    int ans = 0;
    while (ans < k) {
      if (l % (3) != 0 && l % (10) != 3) ans++;
      l++;
    }
    cout << l - 1 << "\n";
  }
  return 0;
}
