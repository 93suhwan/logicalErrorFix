#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int res[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    int cnt = 0;
    for (int i = 1;; i++) {
      if (i % 3 == 0 || i % 10 == 3) continue;
      if (i % 3 != 0 && i % 10 != 3) {
        cnt++;
        if (cnt == k) {
          cout << i << endl;
          break;
        }
      }
    }
  }
  return 0;
}
