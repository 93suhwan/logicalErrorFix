#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long k;
    cin >> k;
    long long row = sqrt(k), col = sqrt(k);
    if (ceil(sqrt(k)) == floor(sqrt(k)))
      cout << row << " "
           << "1"
           << "\n";
    else {
      long long dif = k - row * row;
      if (dif < (row + 1)) {
        row = dif;
        col++;
      } else if (dif > row + 1) {
        row++;
        col = col - (dif - row - 1);
      } else {
        row++;
        col++;
      }
      cout << row << " " << col << "\n";
    }
  }
  return 0;
}
