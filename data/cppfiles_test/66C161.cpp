#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n-- > 0) {
    int t, count = 0, temp, f;
    cin >> f;
    t = f;
    for (int l = 1; l <= t; l++) {
      if (l % 3 == 0 || l % 10 == 3) {
        t++;
      }
    }
    cout << t << endl;
  }
  return 0;
}
