#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void solver() {
  int k;
  cin >> k;
  int r = 1;
  while (r * r < k) {
    r++;
  }
  if (r == 1) {
    cout << 1 << " " << 1 << endl;
  } else {
    int i = 1, j = r;
    int temp = (r - 1) * (r - 1) + 1;
    while (i < r && temp < k) {
      i++;
      temp++;
    }
    if (temp == k) {
      cout << i << " " << j << endl;
      return;
    }
    i = r;
    j = r;
    while (j >= 1 && temp < k) {
      j--;
      temp++;
    }
    cout << i << " " << j << endl;
  }
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    solver();
  }
  return 0;
}
