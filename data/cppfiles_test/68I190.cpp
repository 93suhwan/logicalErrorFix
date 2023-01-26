#include <bits/stdc++.h>
using namespace std;
int main() {
  int z;
  cin >> z;
  while (z--) {
    int k;
    cin >> k;
    int row, col;
    int j;
    for (int i = 1; i * i < k; i++) {
      j = i;
    }
    int a = j * j;
    int b = j + 1;
    int c = a + b;
    if (k <= c) {
      col = b;
      int p = a + 1;
      int cnt = 1;
      while (p < k) {
        cnt++;
        p++;
      }
      row = cnt;
      cout << row << " " << col << endl;
    } else {
      row = j + 1;
      int cnt = 1;
      int q = c;
      while (q < k) {
        cnt++;
        q++;
      }
      cnt--;
      col = b - cnt;
      cout << row << " " << col << endl;
    }
  }
  return 0;
}
