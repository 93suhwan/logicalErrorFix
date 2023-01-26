#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int ans[t];
  for (int l = 0; l < t; l++) {
    int k, n, i;
    cin >> k;
    i = k % 18;
    if (i == 1)
      n = 1;
    else if (i == 2)
      n = 2;
    else if (i == 3)
      n = 4;
    else if (i == 4)
      n = 5;
    else if (i == 5)
      n = 7;
    else if (i == 6)
      n = 8;
    else if (i == 7)
      n = 10;
    else if (i == 8)
      n = 11;
    else if (i == 9)
      n = 14;
    else if (i == 10)
      n = 16;
    else if (i == 11)
      n = 17;
    else if (i == 12)
      n = 19;
    else if (i == 13)
      n = 20;
    else if (i == 14)
      n = 22;
    else if (i == 15)
      n = 25;
    else if (i == 16)
      n = 26;
    else if (i == 17)
      n = 28;
    else if (i == 0) {
      n = 29;
      k--;
    }
    ans[l] = (30 * (k / 18)) + n;
  }
  for (int l = 0; l < t; l++) {
    cout << ans[l] << endl;
  }
  return 0;
}
