#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, r, n;
  int b = l;
  cin >> n;
  while (n > 0) {
    cin >> l;
    cin >> r;
    if (r % 2 == 0) {
      b = max(l, r / 2 + 1);
    } else {
      b = max(l, (r + 1) / 2);
    }
    cout << r % b;
    n--;
  }
}
