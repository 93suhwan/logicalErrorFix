#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n;
  int sq, cb, count = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    sq = (int)sqrt(i);
    cb = (int)cbrt(i);
    if (sq * sq == i || cb * cb * cb == i) {
      count++;
    }
  }
  cout << count << endl;
}
