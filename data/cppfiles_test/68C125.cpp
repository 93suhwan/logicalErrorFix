#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    int current = 1;
    int counter = 1;
    int col = 1;
    while (k >= current + counter) {
      current += counter;
      counter += 2;
      col++;
    }
    int row = k - current + 1;
    if (row <= col)
      cout << row << " " << col << '\n';
    else
      cout << col << " " << (col - (row - col)) << '\n';
  }
  return 0;
}
