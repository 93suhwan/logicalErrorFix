#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k, row, col, ans;
    cin >> k;
    int num = ceil(sqrt(k));
    int sq = num * num;
    int d = sq - k;
    if (d < num) {
      row = num;
      col = d + 1;
    } else {
      col = num;
      d -= num;
      d = num - d - 1;
      row = d;
    }
    cout << row << " " << col << endl;
  }
  return 0;
}
