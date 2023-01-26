#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n-- > 0) {
    int t, count = 0, temp, f;
    cin >> t;
    for (int l = 1; l <= t; l++) {
      if (l % 3 == 0 || l % 10 == 0) {
        t++;
      }
    }
    cout << count + t << endl;
  }
  return 0;
}
