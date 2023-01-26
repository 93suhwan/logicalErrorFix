#include <bits/stdc++.h>
using namespace std;
int t, a, b, c;
int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    int check = -1;
    int max_number = (max(a, b) - min(a, b) + abs(a - b));
    int x = c + max_number / 2, y = c - max_number / 2;
    if (c > max_number || a >= max_number || b >= max_number) {
      cout << -1 << endl;
      continue;
    }
    if (x <= max_number && x >= 1 && x != a && x != b && c <= max_number)
      check = x;
    if (y <= max_number && y >= 1 && y != a && y != b && c <= max_number)
      check = y;
    cout << check << endl;
  }
}
