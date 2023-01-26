#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long n, sq, k, tmp;
    cin >> n;
    sq = sqrt(n);
    for (k = sq;; k++) {
      if (k * (k + 1) + 1 >= n) break;
    }
    tmp = k * (k + 1) + 1;
    if (n < tmp) {
      if (n >= tmp - k) {
        cout << k + 1 - (tmp - n) << " ";
        cout << k + 1;
      } else {
        long tp = k * (k - 1) + 1;
        cout << k << " ";
        cout << k - (n - tp);
      }
    } else if (n == tmp)
      cout << k + 1 << " " << k + 1;
    else {
      cout << k + 1;
      cout << k + 1 - (n - tmp);
    }
    cout << endl;
  }
}
