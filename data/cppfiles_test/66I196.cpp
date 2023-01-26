#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int count = 0;
    if (n == 1) {
      count = 1;
      cout << count;
      break;
    } else if (n == 2) {
      count = 2;
      cout << count;
      break;
    } else {
      for (int i = 3; i <= n; i++) {
        count++;
        if (count / 3 == 0 || count % 10 == 3) {
          count++;
        }
        cout << count + 2;
      }
    }
  }
  return 0;
}
