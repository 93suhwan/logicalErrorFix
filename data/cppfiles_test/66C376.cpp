#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int k, f = 0;
    cin >> k;
    for (int i = 1; i < 1000000; i++) {
      if (i % 3 != 0 && i % 10 != 3) f++;
      if (f == k) {
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}
