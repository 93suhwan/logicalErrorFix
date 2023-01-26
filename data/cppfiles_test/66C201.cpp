#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    int res = 1;
    int i = 0;
    while (i < k) {
      if ((res % 3) != 0 && res % 10 != 3) {
        res++;
        i++;
      } else {
        res++;
      }
    }
    cout << res - 1 << endl;
  }
}
